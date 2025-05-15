/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** exec_sti
*/

#include "project.h"

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
    unsigned int r2;

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
    int groups[2];

    if (((cb >> 6) & 0b11) != 0b01 || reg < 1 || reg > REG_NUMBER)
        return;
    groups[0] = reg;
    groups[1] = cb;
    sti_exec(resources, process, groups, champion);
}
