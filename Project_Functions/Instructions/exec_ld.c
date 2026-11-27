/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** exec_ld
*/

#include "project.h"

void exec_ld(resources_t *resources, champion_t *champion,
    process_t *process)
{
    instr_t instr;
    int value = 0;
    int reg = 0;

    if (decode_instruction(resources, process, &instr) == -1)
        return;
    value = instr.args[0].value;
    reg = instr.args[1].reg;
    process->registers[reg - 1] = value;
    process->carry = (value == 0) ? true : false;
}
