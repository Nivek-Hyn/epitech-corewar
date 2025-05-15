/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** exec_ld
*/

#include "project.h"

static void exec_ld_two(int reg, int value,
    resources_t *resources, process_t *process)
{
    if (reg < 1 || reg > REG_NUMBER)
        return;
    process->registers[reg - 1] = value;
    process->carry = (value == 0) ? true : false;
}

void exec_ld(resources_t *resources, champion_t *champion,
    process_t *process)
{
    uint8_t coding_byte = resources->arena[(process->pc + 1) % MEM_SIZE];
    uint8_t type1 = (coding_byte >> 6) & 0b11;
    uint8_t type2 = (coding_byte >> 4) & 0b11;
    uint32_t value = 0;
    int reg = 0;
    unsigned int offset = 0;

    if (!((type1 == 0b10 || type1 == 0b11) && type2 == 0b01))
        return;
    if (type1 == 0b10) {
        value =
            get_parameter_value(resources, (process->pc + 2) % MEM_SIZE, 4);
        reg = get_parameter_value(resources, (process->pc + 6) % MEM_SIZE, 1);
    } else {
        offset = get_parameter_value(resources, FORMULA_OFFSET);
        value = get_parameter_value(resources, FORMULA_VALUE);
        reg = get_parameter_value(resources, (process->pc + 4) % MEM_SIZE, 1);
    }
    exec_ld_two(reg, value, resources, process);
}
