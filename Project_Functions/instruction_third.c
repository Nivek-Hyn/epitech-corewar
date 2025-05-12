/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** instruction_third
*/

#include "project.h"

void exec_xor(resources_t *resources, champion_t *champion,
    process_t *process)
{
    int first_register_index =
        get_parameter_value(resources, (process->pc + 2) % MEM_SIZE, 1);
    int second_register_index =
        get_parameter_value(resources, (process->pc + 3) % MEM_SIZE, 1);
    int third_register_index =
        get_parameter_value(resources, (process->pc + 4) % MEM_SIZE, 1);

    if (first_register_index < 1 || first_register_index > REG_NUMBER ||
        second_register_index < 1 || second_register_index > REG_NUMBER ||
        third_register_index < 1 || third_register_index > REG_NUMBER)
        return;
    process->registers[third_register_index - 1] =
        process->registers[first_register_index - 1] ^
            process->registers[second_register_index - 1];
    process->carry =
        (process->registers[third_register_index - 1] == 0) ? 1 : 0;
}

void exec_zjmp(resources_t *resources, champion_t *champion,
    process_t *process)
{
    short index =
        (short)get_parameter_value(resources, (process->pc + 1) % MEM_SIZE, 2);

    if (process->carry == 1)
        process->pc = (process->pc + index % IDX_MOD) % MEM_SIZE;
}

static void sti_write(resources_t *resources,
    int addr, int val, champion_t *champion)
{
    for (int i = 0; i < 4; i++) {
        resources->arena[(addr + i) % MEM_SIZE] = (val >> (24 - i * 8)) & 0xFF;
        resources->owner[(addr + i) % MEM_SIZE] = champion->prog_number;
    }
}

static void sti_final(resources_t *resources, process_t *process,
    int reg, sti_param_t p)
{
    int val = process->registers[reg - 1];
    int pc = p.new_pc;
    int r3;

    if (p.type3 == 0b01) {
        r3 = resources->arena[pc % MEM_SIZE];
        if (r3 < 1 || r3 > REG_NUMBER)
            return;
        p.value2 += process->registers[r3 - 1];
        pc = (pc + 1) % MEM_SIZE;
    } else {
        p.value2 += get_parameter_value(resources, pc % MEM_SIZE, 2);
        pc = (pc + 2) % MEM_SIZE;
    }
    process->pc = pc;
    sti_write(resources, (pc +
        (p.value2 % IDX_MOD)) % MEM_SIZE, val, p.champion);
}

static void sti_exec(resources_t *resources, process_t *process,
    int *groups, champion_t *champion)
{
    int reg = groups[0];
    uint8_t cb = groups[1];
    int v2 = 0;
    int pc = process->pc;
    uint8_t t2 = (cb >> 4) & 0b11;
    uint8_t t3 = (cb >> 2) & 0b11;
    int r2;

    if (t2 == 0b01) {
        r2 = resources->arena[(pc + 3) % MEM_SIZE];
        if (r2 < 1 || r2 > REG_NUMBER)
            return;
        v2 = process->registers[r2 - 1];
        pc = (pc + 4) % MEM_SIZE;
    } else {
        v2 = get_parameter_value(resources, (pc + 3) % MEM_SIZE, 2);
        pc = (pc + 5) % MEM_SIZE;
    }
    sti_final(resources, process, reg, (sti_param_t){v2, t3, pc, champion});
}

void exec_sti(resources_t *resources, champion_t *champion,
    process_t *process)
{
    uint8_t cb = resources->arena[(process->pc + 1) % MEM_SIZE];
    int reg = resources->arena[(process->pc + 2) % MEM_SIZE];
    int groups[1];

    if (((cb >> 6) & 0b11) != 0b01 || reg < 1 || reg > REG_NUMBER)
        return;
    groups[0] = reg;
    groups[1] = cb;
    sti_exec(resources, process, groups, champion);
}

void exec_fork(resources_t *resources, champion_t *champion,
    process_t *process)
{
    short index =
        (short)get_parameter_value(resources, (process->pc + 1) % MEM_SIZE, 2);
    process_t *current = champion->processes;

    champion->processes = create_process(champion->processes);
    while (current->next)
        current = current->next;
    current->alive = process->alive;
    current->carry = process->carry;
    current->waiting_cycles = process->waiting_cycles;
    current->current_instruction = process->current_instruction;
    for (int i = 0; i < REG_NUMBER; i++)
        current->registers[i] = process->registers[i];
    current->pc = (current->pc + index % IDX_MOD) % MEM_SIZE;
}

void exec_lld(resources_t *resources, champion_t *champion,
    process_t *process)
{
    uint8_t coding_byte = resources->arena[(process->pc + 1) % MEM_SIZE];
    uint8_t type1 = (coding_byte >> 6) & 0b11;
    uint8_t type2 = (coding_byte >> 4) & 0b11;
    int32_t value = 0;
    int reg = 0;
    int offset = 0;

    if (!((type1 == 0b10 || type1 == 0b11) && type2 == 0b01))
        return;
    if (type1 == 0b10) {
        value = get_bytes_live((process->pc + 2) % MEM_SIZE, resources->arena);
        reg = resources->arena[(process->pc + 6) % MEM_SIZE];
        process->pc = (process->pc + 7) % MEM_SIZE;
    } else {
        offset = get_parameter_value(resources, FORMULA_OFFSET);
        value = get_parameter_value(resources, FORMULA_SECOND);
        reg = resources->arena[(process->pc + 4) % MEM_SIZE];
        process->pc = (process->pc + 5) % MEM_SIZE;
    }
    exec_ld_two(reg, value, resources, process);
}
