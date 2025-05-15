/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** exec_sub
*/

#include "project.h"

void exec_sub(resources_t *resources, champion_t *champion,
    process_t *process)
{
    uint8_t coding_byte = resources->arena[(process->pc + 1) % MEM_SIZE];
    unsigned int reg1 = 0;
    unsigned int reg2 = 0;
    unsigned int reg3 = 0;

    if (!(((coding_byte >> 6) & 0b11) == 0b01 &&
        ((coding_byte >> 4) & 0b11) == 0b01 &&
        ((coding_byte >> 2) & 0b11) == 0b01))
        return;
    reg1 = resources->arena[(process->pc + 2) % MEM_SIZE];
    reg2 = resources->arena[(process->pc + 3) % MEM_SIZE];
    reg3 = resources->arena[(process->pc + 4) % MEM_SIZE];
    if (reg1 < 1 || reg1 > REG_NUMBER || reg2 < 1 || reg2 > REG_NUMBER ||
        reg3 < 1 || reg3 > REG_NUMBER)
        return;
    process->registers[reg3 - 1] =
        process->registers[reg1 - 1] -
            process->registers[reg2 - 1];
    process->carry =
        (process->registers[reg3 - 1] == 0) ? true : false;
}
