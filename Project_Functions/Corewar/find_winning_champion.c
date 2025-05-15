/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** find_winning_champion
*/

#include "project.h"

int find_alive_processes(champion_t *champion)
{
    process_t *current = champion->processes;
    int alive_count = 0;

    while (current) {
        if (current->alive == 1) {
            alive_count++;
        }
        current = current->next;
    }
    return alive_count;
}

champion_t *find_winning_champion(resources_t *resources)
{
    champion_t *winner = NULL;
    int alives = 0;
    int max_alive = 0;

    for (int i = 0; resources->champion_list[i] != NULL; i++) {
        alives = find_alive_processes(resources->champion_list[i]);
        if (alives > max_alive) {
            max_alive = alives;
            winner = resources->champion_list[i];
        }
    }
    return winner;
}
