/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** run_corewar
*/

#include "project.h"

void run_corewar(resources_t *resources)
{
    int cycle_to_die = CYCLE_TO_DIE;
    int cycle_checker = 0;

    printf("nbr_cycle: %d\n", resources->nbr_cycle);
    for (int cycle = 0; champions_left(resources) > 1; cycle++) {
        printf("cycle: %d\n", cycle);
        if (cycle == resources->nbr_cycle)
            print_arena(resources);
        run_all_processes(resources);
        if (cycle_checker > cycle_to_die) {
            //if (check_live(resources) > NBR_LIVE)
            //    cycle_to_die -= CYCLE_DELTA;
            cycle_checker = 0;
        }
        cycle_checker++;
    }
    mega_write(1, "The winner is %s !\n", "Kevin");
}
