/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** exec_st
*/

#include "project.h"

static void st_checking(resources_t *resources,
    process_t *process, champion_t *champion, st_params_t *p)
{
    if (p->type2 == 0b01) {
        p->reg_final = resources->arena[(process->pc + 3) % MEM_SIZE];
        if (p->reg_final >= 1 && p->reg_final <= REG_NUMBER)
            process->registers[p->reg_final - 1] = p->value;
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
    }
}

void exec_st(resources_t *resources, champion_t *champion,
    process_t *process)
{
    uint8_t coding_byte = resources->arena[(process->pc + 1) % MEM_SIZE];
    st_params_t p;
    uint8_t type1 = (coding_byte >> 6) & 0b11;
    int reg = 0;

    p.type2 = (coding_byte >> 4) & 0b11;
    p.value = 0;
    p.offset = 0;
    if (!(type1 == 0b01 && (p.type2 == 0b01 || p.type2 == 0b11)))
        return;
    reg = resources->arena[(process->pc + 2) % MEM_SIZE];
    if (reg < 1 || reg > REG_NUMBER)
        return;
    p.value = process->registers[reg - 1];
    st_checking(resources, process, champion, &p);
}
