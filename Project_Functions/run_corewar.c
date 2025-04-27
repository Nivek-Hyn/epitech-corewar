/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** run_corewar
*/

#include "project.h"

void run_instruction(resources_t *resources, process_t *process)
{
    void (*instructions[16])(resources_t *, process_t *) =
        {exec_live, exec_ld, exec_add, exec_sub, exec_and, exec_or,
            exec_xor, exec_zjmp, exec_ldi, exec_sti, exec_fork, exec_lld,
                exec_lldi, exec_lfork, exec_aff};

    for (int i = 0; op_tab[i].code != 0; i++) {
        if (op_tab[i].code == process->current_instruction)
            instructions[i](resources, process);
    }
}

void run_process(resources_t *resources, process_t *process)
{
    if (process->current_instruction != -1 && process->waiting_cycles == 0) {
        //run_instruction(resources, process);
        // Avancer l'instruction
    }
    if (process->waiting_cycles == 0) {
        process->current_instruction = resources->arena[process->pc];
        for (int i = 0; op_tab[i].code != 0; i++) {
            if (op_tab[i].code == process->current_instruction)
                process->waiting_cycles = op_tab[i].nbr_cycles;
        }
    } else {
        process->waiting_cycles--;
    }
}

void run_champion_processes(resources_t *resources, champion_t *champion)
{
    process_t *current = champion->processes;

    while (current) {
        run_process(resources, current);
        current = current->next;
    }
}

void run_all_processes(resources_t *resources)
{
    for (int i = 0; resources->champion_list[i] != NULL; i++) {
        run_champion_processes(resources, resources->champion_list[i]);
    }
}

void run_corewar(resources_t *resources)
{
    int cycle_to_die = CYCLE_TO_DIE;
    int cycle_checker = 0;

    printf("nbr_cycle: %d\n", resources->nbr_cycle);
    for (int cycle = 0; champions_left(resources) > 1; cycle++) {
        printf("cycle: %d\n", cycle);
        if (cycle == resources->nbr_cycle) {
            print_arena(resources);
            return;
        }
        run_all_processes(resources);
        if (cycle_checker > cycle_to_die) {
            //if (check_live(resources) > NBR_LIVE)
            //    cycle_to_die -= CYCLE_DELTA;
            cycle_checker = 0;
        }
        cycle_checker++;
    }
    //mega_write(1, "The winner is %s !\n", );
}
