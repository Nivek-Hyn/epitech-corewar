/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** exec_sti
*/

#include "project.h"

void exec_sti(resources_t *resources, champion_t *champion,
    process_t *process)
{
    instr_t instr;
    int offset = 0;

    if (decode_instruction(resources, process, &instr) == -1)
        return;
    offset = (instr.args[1].value + instr.args[2].value) % IDX_MOD;
    write_mem(resources, process->pc + offset,
        instr.args[0].value, champion->prog_number);
}
