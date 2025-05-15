/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** exec_aff
*/

#include "project.h"

void exec_aff(resources_t *resources, champion_t *champion,
    process_t *process)
{
    uint8_t coding_byte = resources->arena[(process->pc + 1) % MEM_SIZE];
    uint8_t type1 = (coding_byte >> 6) & 0b11;
    int value;
    int reg;

    if (type1 != 0b01)
        return;
    reg = resources->arena[(process->pc + 2) % MEM_SIZE];
    if (reg < 1 || reg > REG_NUMBER)
        return;
    value = process->registers[reg - 1];
    mega_write(1, "%c\n", value % 256);
}
