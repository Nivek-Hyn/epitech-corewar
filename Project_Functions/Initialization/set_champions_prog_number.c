/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** set_champions_prog_number
*/

#include "project.h"

int prog_number_exists(champion_t **champion_list, int prog_number)
{
    for (int i = 0; champion_list[i] != NULL; i++) {
        if (prog_number == champion_list[i]->prog_number)
            return 1;
    }
    return 0;
}

int get_lowest_unoccupied_prog_number(champion_t **champion_list)
{
    int result = 0;

    while (prog_number_exists(champion_list, result) == 1)
        result++;
    return result;
}

void set_champions_prog_number(resources_t *resources)
{
    for (int i = 0; resources->champion_list[i] != NULL; i++) {
        if (resources->champion_list[i]->prog_number == -1)
            resources->champion_list[i]->prog_number =
                get_lowest_unoccupied_prog_number(resources->champion_list);
    }
}
