/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** create_process
*/

#include "project.h"

process_t *create_process(void)
{
    process_t *new_process = malloc(sizeof(process_t));

    if (check_malloc(new_process, "new_process: Malloc Failed.\n") == -1)
        return NULL;
    new_process->alive = 1;
    for (int i = 0; i < REG_NUMBER; i++)
        new_process->registers[i] = 0;
    new_process->carry = 0;
    new_process->pc = 0;
    new_process->waiting_cycles = 0;
    new_process->current_instruction = -1;
    new_process->next = NULL;
    return new_process;
}
