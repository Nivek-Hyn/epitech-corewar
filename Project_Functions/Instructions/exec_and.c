/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** exec_and
*/

#include "project.h"

static unsigned int get_pc(uint8_t type, unsigned int pc)
{
    if (type == 0b01) {
        pc = (pc + 1) % MEM_SIZE;
    } else if (type == 0b10) {
        pc = (pc + 4) % MEM_SIZE;
    } else {
        pc = (pc + 2) % MEM_SIZE;
    }
    return pc;
}

static int get_reg3(uint8_t type1, uint8_t type2, process_t *process,
    resources_t *resources)
{
    unsigned int reg = 0;
    unsigned int base = (process->pc + 2) % MEM_SIZE;
    unsigned int offset1 = get_pc(type1, base);
    unsigned int offset2 = get_pc(type2, (base + offset1) % MEM_SIZE);
    unsigned int reg_pos = (base + offset1 + offset2) % MEM_SIZE;

    reg = resources->arena[reg_pos];
    if (reg < 1 || reg > REG_NUMBER)
        return -1;
    return reg;
}

static int get_val2(uint8_t type, uint8_t type1, process_t *process,
    resources_t *resources)
{
    unsigned int val = 0;
    unsigned int reg = 0;
    unsigned int base = (process->pc + 2) % MEM_SIZE;
    unsigned int offset1 = get_pc(type1, base);
    unsigned int pc = (base + offset1) % MEM_SIZE;

    if (type == 0b01) {
        reg = resources->arena[pc];
        if (reg < 1 || reg > REG_NUMBER)
            return -1;
        val = process->registers[reg - 1];
    } else if (type == 0b10) {
        val = get_parameter_value(resources, pc, 4);
    } else {
        val = get_parameter_value(resources, pc, 2);
    }
    return val;
}

static int get_val1(uint8_t type, process_t *process,
    resources_t *resources)
{
    unsigned int val = 0;
    unsigned int reg = 0;

    if (type == 0b01) {
        reg = resources->arena[(process->pc + 2) % MEM_SIZE];
        if (reg < 1 || reg > REG_NUMBER)
            return -1;
        val = process->registers[reg - 1];
    } else if (type == 0b10) {
        val = get_parameter_value(resources,
            (process->pc + 2) % MEM_SIZE, 4);
    } else {
        val = get_parameter_value(resources,
            (process->pc + 2) % MEM_SIZE, 2);
    }
    return val;
}

void exec_and(resources_t *resources, champion_t *champion,
    process_t *process)
{
    uint8_t coding_byte = resources->arena[(process->pc + 1) % MEM_SIZE];
    uint8_t type1 = (coding_byte >> 6) & 0b11;
    uint8_t type2 = (coding_byte >> 4) & 0b11;
    uint8_t type3 = (coding_byte >> 2) & 0b11;
    unsigned int val1 = 0;
    unsigned int val2 = 0;
    unsigned int reg3 = 0;

    if (!((type1 == 0b01 || type1 == 0b10 || type1 == 0b11) &&
        (type2 == 0b01 || type2 == 0b10 || type2 == 0b11) && type3 == 0b01))
        return;
    val1 = get_val1(type1, process, resources);
    val2 = get_val2(type2, type1, process, resources);
    reg3 = get_reg3(type1, type2, process, resources);
    if (val1 == -1 || val2 == -1 || reg3 == -1)
        return;
    process->registers[reg3 - 1] = val1 & val2;
    process->carry = (process->registers[reg3 - 1] == 0) ? true : false;
}
