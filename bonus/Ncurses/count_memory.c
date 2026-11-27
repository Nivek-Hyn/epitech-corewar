/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** count_memory
*/

#include "project.h"

int count_processes(champion_t *champion)
{
    int count = 0;

    for (process_t *p = champion->processes; p != NULL; p = p->next)
        count += (p->alive == 1);
    return count;
}

int count_territory(resources_t *resources, int prog_number)
{
    int count = 0;

    for (int i = 0; i < MEM_SIZE; i++)
        count += (resources->owner[i] == prog_number);
    return count;
}

int count_owned(resources_t *resources)
{
    int count = 0;

    for (int i = 0; i < MEM_SIZE; i++)
        count += (resources->owner[i] != -1);
    return count;
}
