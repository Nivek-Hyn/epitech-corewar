/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** instructions
*/

#include "project.h"

uint32_t get_bytes_live(int pc, char *arena)
{
    uint32_t bytes = 0;

    for (int i = 0; i < 4; i++)
        bytes = (bytes << 8) | (char)arena[(pc + i) % MEM_SIZE];
    bytes = convert_big_endian_to_little_endian(bytes);
    return bytes;
}

void exec_live(resources_t *resources, champion_t *champion,
    process_t *process)
{
    uint32_t number = get_bytes_live(process->pc + 1, resources->arena);

    if (number == champion->prog_number) {
        process->alive = 1;
        mega_write(1, "The player %d(%s) is alive.\n",
            champion->prog_number, champion->name);
    }
}

void exec_ld_two(int reg, int value,
    resources_t *resources, process_t *process)
{
    if (reg < 1 || reg > REG_NUMBER)
        return;
    process->registers[reg - 1] = value;
    process->carry = (value == 0) ? 1 : 0;
}

void exec_ld(resources_t *resources, champion_t *champion,
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
        value = get_parameter_value(resources, FORMULA_VALUE);
        reg = resources->arena[(process->pc + 4) % MEM_SIZE];
        process->pc = (process->pc + 5) % MEM_SIZE;
    }
    exec_ld_two(reg, value, resources, process);
}

void st_checking(resources_t *resources,
    process_t *process, champion_t *champion, st_params_t *p)
{
    if (p->type2 == 0b01) {
        p->reg_final = resources->arena[(process->pc + 3) % MEM_SIZE];
        if (p->reg_final >= 1 && p->reg_final <= REG_NUMBER)
            process->registers[p->reg_final - 1] = p->value;
        process->pc = ((process->pc + 4) % MEM_SIZE);
    } else {
        p->offset = get_parameter_value(resources,
            (process->pc + 3) % MEM_SIZE, 2);
        p->addr_final = (process->pc + (p->offset % IDX_MOD)) % MEM_SIZE;
        for (int i = 0; i < 4; i++) {
            resources->arena[(p->addr_final + i) % MEM_SIZE] =
                (p->value >> (24 - i * 8)) & 0xFF;
            resources->owner[(p->addr_final + i) % MEM_SIZE] =
                champion->prog_number;
        }
        process->pc = (process->pc + 5) % MEM_SIZE;
    }
}
