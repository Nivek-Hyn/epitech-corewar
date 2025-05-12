/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** run_all_processes
*/

#include "project.h"

void set_process_waiting_cycles(process_t *process)
{
    for (int i = 0; op_tab[i].code != 0; i++) {
        if (op_tab[i].code == process->current_instruction)
            process->waiting_cycles = op_tab[i].nbr_cycles;
    }
}

void run_process(resources_t *resources, champion_t *champion,
    process_t *process)
{
    if (process->current_instruction != -1 && process->waiting_cycles == 0) {
        run_instruction(resources, champion, process);
        advance_instruction(resources, process);
    }
    if (process->waiting_cycles == 0) {
        process->current_instruction = resources->arena[process->pc];
        set_process_waiting_cycles(process);
    } else {
        process->waiting_cycles--;
    }
}

void run_champion_processes(resources_t *resources, champion_t *champion)
{
    process_t *current = champion->processes;

    while (current) {
        run_process(resources, champion, current);
        current = current->next;
    }
}

void run_all_processes(resources_t *resources)
{
    for (int i = 0; resources->champion_list[i] != NULL; i++) {
        run_champion_processes(resources, resources->champion_list[i]);
    }
}
