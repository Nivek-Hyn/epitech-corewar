/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** champions_left
*/

#include "project.h"

int processes_left(champion_t *champion)
{
    int count = 0;

    for (process_t *current = champion->processes;
            current; current = current->next) {
        if (current->alive == 1)
            count++;
    }
    return count;
}

int champions_left(resources_t *resources)
{
    int count = 0;

    for (int i = 0; resources->champion_list[i] != NULL; i++) {
        if (processes_left(resources->champion_list[i]) > 0)
            count++;
    }
    return count;
}
