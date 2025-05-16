/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** run_corewar
*/

#include "project.h"

void check_processes_live(resources_t *resources, champion_t *champion)
{
    process_t *current = champion->processes;

    while (current) {
        if (current->live == true) {
            current->alive = 1;
        } else {
            current->alive = 0;
        }
        current->live = false;
        current = current->next;
    }
}

void check_champions_processes_live(resources_t *resources)
{
    for (int i = 0; resources->champion_list[i] != NULL; i++)
        check_processes_live(resources, resources->champion_list[i]);
}

void cycles_and_lives_manager(resources_t *resources,
    int *cycle_to_die, int *cycle_checker)
{
    if (*cycle_checker > *cycle_to_die) {
        if (resources->total_lives > NBR_LIVE) {
            *cycle_to_die -= CYCLE_DELTA;
            resources->total_lives = 0;
        }
        check_champions_processes_live(resources);
        *cycle_checker = 0;
    }
    (*cycle_checker)++;
}

void run_corewar(resources_t *resources)
{
    int cycle_to_die = CYCLE_TO_DIE;
    int cycle_checker = 0;
    champion_t *winner = NULL;

    for (int cycle = 0; champions_left(resources) > 1; cycle++) {
        if (cycle == resources->nbr_cycle) {
            print_arena(resources);
            return;
        }
        run_all_processes(resources);
        cycles_and_lives_manager(resources, &cycle_to_die, &cycle_checker);
    }
    winner = find_winning_champion(resources);
    if (winner == NULL) {
        mega_write(1, "No winner found.\n");
        return;
    }
    mega_write(1, "The winner is player %d(%s) !\n",
        winner->prog_number, winner->name);
}
