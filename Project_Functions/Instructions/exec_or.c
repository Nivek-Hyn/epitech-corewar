/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** exec_or
*/

#include "project.h"

void exec_or(resources_t *resources, champion_t *champion,
    process_t *process)
{
    instr_t instr;
    int reg = 0;

    if (decode_instruction(resources, process, &instr) == -1)
        return;
    reg = instr.args[2].reg;
    process->registers[reg - 1] = instr.args[0].value | instr.args[1].value;
    process->carry = (process->registers[reg - 1] == 0) ? true : false;
}
