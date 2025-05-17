/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** corewar_system
*/

#include "project.h"

void corewar_system(resources_t *resources, graphical_t *graphical)
{
    graphical->cycle++;
    run_all_processes_graphical(resources);
    cycles_and_lives_manager(resources,
        &graphical->cycle_to_die, &graphical->cycle_checker);
    if (champions_left(resources) < 1) {
        graphical->paused = 2;
        graphical->winner = find_winning_champion(resources);
    }
}
