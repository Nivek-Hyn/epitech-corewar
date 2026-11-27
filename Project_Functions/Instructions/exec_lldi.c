/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** exec_lldi
*/

#include "project.h"

void exec_lldi(resources_t *resources, champion_t *champion,
    process_t *process)
{
    instr_t instr;
    int addr = 0;
    int reg = 0;

    if (decode_instruction(resources, process, &instr) == -1)
        return;
    addr = process->pc + instr.args[0].value + instr.args[1].value;
    reg = instr.args[2].reg;
    process->registers[reg - 1] = read_mem(resources, addr, REG_SIZE);
    process->carry = (process->registers[reg - 1] == 0) ? true : false;
}
