/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** exec_st
*/

#include "project.h"

void exec_st(resources_t *resources, champion_t *champion,
    process_t *process)
{
    instr_t instr;
    int value = 0;

    if (decode_instruction(resources, process, &instr) == -1)
        return;
    value = instr.args[0].value;
    if (instr.args[1].type == 0b01) {
        process->registers[instr.args[1].reg - 1] = value;
        return;
    }
    write_mem(resources, process->pc + instr.args[1].raw % IDX_MOD,
        value, champion->prog_number);
}
