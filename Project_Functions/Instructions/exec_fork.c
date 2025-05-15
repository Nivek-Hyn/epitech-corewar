/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** exec_fork
*/

#include "project.h"

void exec_fork(resources_t *resources, champion_t *champion,
    process_t *process)
{
    unsigned short index = (unsigned short)get_parameter_value(resources,
        (process->pc + 1) % MEM_SIZE, 2);
    process_t *current = champion->processes;

    champion->processes = create_process(champion->processes);
    while (current->next)
        current = current->next;
    current->alive = process->alive;
    current->carry = process->carry;
    current->waiting_cycles = 0;
    current->current_instruction = -1;
    for (int i = 0; i < REG_NUMBER; i++)
        current->registers[i] = process->registers[i];
    current->pc = (current->pc + index % IDX_MOD) % MEM_SIZE;
    current->forked = true;
}
