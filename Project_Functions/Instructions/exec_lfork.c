/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** exec_lfork
*/

#include "project.h"

void exec_lfork(resources_t *resources, champion_t *champion,
    process_t *process)
{
    int index = read_mem(resources, process->pc + 1, IND_SIZE);
    int parent_pc = process->pc;
    process_t *child = NULL;

    champion->processes = create_process(champion->processes);
    child = champion->processes;
    while (child->next)
        child = child->next;
    child->alive = process->alive;
    child->carry = process->carry;
    child->waiting_cycles = 1;
    child->current_instruction = -1;
    for (int i = 0; i < REG_NUMBER; i++)
        child->registers[i] = process->registers[i];
    child->pc = mem_addr(parent_pc + index);
    child->forked = true;
}
