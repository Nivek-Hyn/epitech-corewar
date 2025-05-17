/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** run_all_processes
*/

#include "project.h"

void set_process_waiting_cycles_graphical(process_t *process)
{
    for (int i = 0; op_tab[i].code != 0; i++) {
        if (op_tab[i].code == process->current_instruction)
            process->waiting_cycles = op_tab[i].nbr_cycles;
    }
}

void run_process_graphical(resources_t *resources, champion_t *champion,
    process_t *process)
{
    uint8_t opcode = resources->arena[process->pc % MEM_SIZE];

    if (process->current_instruction == -1) {
        if (opcode >= 1 && opcode <= NBR_INSTRUCTIONS) {
            process->current_instruction = opcode;
            set_process_waiting_cycles_graphical(process);
            process->waiting_cycles--;
        } else {
            process->pc = (process->pc + 1) % MEM_SIZE;
        }
        return;
    }
    if (process->waiting_cycles > 0) {
        process->waiting_cycles--;
        return;
    }
    run_instruction_graphical(resources, champion, process);
    advance_instruction(resources, process);
    process->current_instruction = -1;
}

void run_champion_processes_graphical(resources_t *resources,
    champion_t *champion)
{
    process_t *current = champion->processes;

    while (current) {
        if (current->forked == true) {
            current->forked = false;
            continue;
        }
        if (current->alive == 1)
            run_process_graphical(resources, champion, current);
        current = current->next;
    }
}

void run_all_processes_graphical(resources_t *resources)
{
    for (int i = 0; resources->champion_list[i] != NULL; i++) {
        run_champion_processes_graphical(resources,
            resources->champion_list[i]);
    }
}
