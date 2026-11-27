/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** exec_zjmp
*/

#include "project.h"

void exec_zjmp(resources_t *resources, champion_t *champion,
    process_t *process)
{
    int index = read_mem(resources, process->pc + 1, IND_SIZE);

    if (process->carry == true)
        process->pc = mem_addr(process->pc + index % IDX_MOD);
}
