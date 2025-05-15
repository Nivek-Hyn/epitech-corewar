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
    unsigned short index =
        (unsigned short)get_parameter_value(
            resources, (process->pc + 1) % MEM_SIZE, 2);

    if (process->carry == true)
        process->pc = (process->pc + index % IDX_MOD) % MEM_SIZE;
}
