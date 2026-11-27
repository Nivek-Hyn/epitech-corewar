/*
** EPITECH PROJECT, 2025
** Unit Tests
** File description:
** Virtual machine instructions
*/

#include <criterion/criterion.h>
#include <string.h>
#include "project.h"

static resources_t res;
static champion_t champ;
static champion_t *list[2];
static flags_t flags;

static process_t *setup(int pc, const uint8_t *code, int size)
{
    memset(&res, 0, sizeof(res));
    memset(&champ, 0, sizeof(champ));
    memset(&flags, 0, sizeof(flags));
    champ.prog_number = 1;
    champ.name = "Test";
    champ.processes = create_process(NULL);
    champ.processes->pc = pc;
    list[0] = &champ;
    list[1] = NULL;
    res.champion_list = list;
    res.nb_champion = 1;
    res.flags = &flags;
    for (int i = 0; i < size; i++)
        res.arena[mem_addr(pc + i)] = code[i];
    return champ.processes;
}

static void step(process_t *process)
{
    process->current_instruction = res.arena[process->pc];
    run_instruction(&res, &champ, process);
    advance_instruction(&res, process);
    process->current_instruction = -1;
}

static process_t *last_process(void)
{
    process_t *current = champ.processes;

    while (current->next)
        current = current->next;
    return current;
}

Test(memory, addresses_wrap_and_values_are_signed)
{
    uint8_t code[] = {0xFF, 0xFB};

    setup(MEM_SIZE - 1, code, 2);
    cr_assert_eq(mem_addr(-1), MEM_SIZE - 1);
    cr_assert_eq(mem_addr(MEM_SIZE + 3), 3);
    cr_assert_eq(read_mem(&res, MEM_SIZE - 1, 2), -5);
    cr_assert_eq(read_mem(&res, -1, 2), -5);
}

Test(zjmp, jumps_backwards_when_carry_is_set)
{
    uint8_t code[] = {0x09, 0xFF, 0xF6};
    process_t *p = setup(100, code, 3);

    p->carry = true;
    step(p);
    cr_assert_eq(p->pc, 90);
}

Test(zjmp, steps_over_itself_when_carry_is_clear)
{
    uint8_t code[] = {0x09, 0xFF, 0xF6};
    process_t *p = setup(100, code, 3);

    p->carry = false;
    step(p);
    cr_assert_eq(p->pc, 103);
}

Test(zjmp, offset_is_reduced_by_idx_mod)
{
    uint8_t code[] = {0x09, 0x02, 0x58};
    process_t *p = setup(10, code, 3);

    p->carry = true;
    step(p);
    cr_assert_eq(p->pc, 10 + 600 % IDX_MOD);
}

Test(fork, child_starts_relative_to_the_parent)
{
    uint8_t code[] = {0x0c, 0xFF, 0xEC};
    process_t *p = setup(1000, code, 3);

    p->registers[0] = 42;
    p->carry = true;
    step(p);
    cr_assert_eq(last_process()->pc, 980);
    cr_assert_eq(last_process()->registers[0], 42);
    cr_assert_eq(last_process()->carry, true);
    cr_assert_eq(p->pc, 1003);
}

Test(fork, uses_idx_mod_but_lfork_does_not)
{
    uint8_t fork_code[] = {0x0c, 0x02, 0x58};
    uint8_t lfork_code[] = {0x0f, 0x02, 0x58};
    process_t *p = setup(1000, fork_code, 3);

    step(p);
    cr_assert_eq(last_process()->pc, 1000 + 600 % IDX_MOD);
    p = setup(1000, lfork_code, 3);
    step(p);
    cr_assert_eq(last_process()->pc, 1600);
}

Test(sti, writes_relative_to_the_instruction)
{
    uint8_t code[] = {0x0b, 0x68, 0x01, 0xFF, 0xF8, 0x00, 0x02};
    process_t *p = setup(200, code, 7);

    p->registers[0] = 0x11223344;
    step(p);
    cr_assert_eq(read_mem(&res, 194, 4), 0x11223344);
    cr_assert_eq(res.owner[194], 1);
    cr_assert_eq(p->pc, 207, "pc %d", p->pc);
}

Test(st, stores_at_a_negative_offset)
{
    uint8_t code[] = {0x03, 0x70, 0x01, 0xFF, 0xF0};
    process_t *p = setup(64, code, 5);

    p->registers[0] = -7;
    step(p);
    cr_assert_eq(read_mem(&res, 48, 4), -7);
    cr_assert_eq(p->pc, 69);
}

Test(ld, indirect_reads_four_bytes_before_pc)
{
    uint8_t code[] = {0xDE, 0xAD, 0xBE, 0xEF, 0x02, 0xD0, 0xFF, 0xFC, 0x02};
    process_t *p = setup(300, code, 9);

    p->pc = 304;
    step(p);
    cr_assert_eq((unsigned int)p->registers[1], 0xDEADBEEF);
    cr_assert_eq(p->carry, false);
    cr_assert_eq(p->pc, 309);
}

Test(ld, direct_zero_sets_carry)
{
    uint8_t code[] = {0x02, 0x90, 0, 0, 0, 0, 0x03};
    process_t *p = setup(0, code, 7);

    p->registers[2] = 9;
    step(p);
    cr_assert_eq(p->registers[2], 0);
    cr_assert_eq(p->carry, true);
}

Test(and, works_on_direct_values_and_registers)
{
    uint8_t code[] = {0x06, 0xA4, 0, 0, 0xF0, 0xF0, 0, 0, 0xFF, 0x00, 0x03};
    uint8_t or_code[] = {0x07, 0x54, 0x01, 0x02, 0x03};
    process_t *p = setup(500, code, 11);

    step(p);
    cr_assert_eq(p->registers[2], 0xF000);
    cr_assert_eq(p->pc, 511);
    p = setup(500, or_code, 5);
    p->registers[0] = -1;
    p->registers[1] = 0;
    step(p);
    cr_assert_eq(p->registers[2], -1);
    cr_assert_eq(p->carry, false);
}

Test(ldi, adds_both_indexes)
{
    uint8_t code[] = {0x0a, 0xA4, 0x00, 0x0D, 0xFF, 0xFE, 0x05,
        0, 0, 0, 0, 0x12, 0x34, 0x56, 0x78};
    process_t *p = setup(700, code, 15);

    step(p);
    cr_assert_eq(p->registers[4], 0x12345678);
    cr_assert_eq(p->pc, 707);
}

Test(decode, rejects_a_bad_register)
{
    uint8_t code[] = {0x04, 0x54, 0x01, 0x11, 0x03};
    process_t *p = setup(0, code, 5);

    p->registers[2] = 5;
    step(p);
    cr_assert_eq(p->registers[2], 5);
    cr_assert_eq(p->pc, 5);
}

Test(live, credits_the_player_named_in_the_argument)
{
    uint8_t code[] = {0x01, 0, 0, 0, 0x01};
    process_t *p = setup(0, code, 5);

    p->alive = 0;
    step(p);
    cr_assert_eq(p->live, true);
    cr_assert_eq(res.last_live, &champ);
    cr_assert_eq(p->pc, 5);
}

Test(winner, falls_back_to_the_last_player_reported_alive)
{
    uint8_t code[] = {0x01, 0, 0, 0, 0x01};
    process_t *p = setup(0, code, 5);

    step(p);
    p->alive = 0;
    cr_assert_eq(find_winning_champion(&res), &champ);
}

Test(options, n_and_a_work_without_dump)
{
    char *argv[] = {"./corewar", "-n", "2", "-a", "100", NULL};
    int i = 1;

    setup(0, NULL, 0);
    res.nbr_cycle = -1;
    cr_assert_eq(parse_command_arg(&res, 5, argv, &i), 0);
    i = 3;
    cr_assert_eq(parse_command_arg(&res, 5, argv, &i), 0);
    cr_assert_eq(flags.prog_number, 2);
    cr_assert_eq(flags.load_address, 100);
}

Test(options, dump_needs_a_number)
{
    char *argv[] = {"./corewar", "-dump", NULL};
    int i = 1;

    setup(0, NULL, 0);
    cr_assert_eq(parse_command_arg(&res, 2, argv, &i), -1);
}
