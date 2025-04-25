/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** free_all
*/

#include "project.h"

void free_all(resources_t *resources)
{
    for (int i = 0; resources->champion_list &&
        resources->champion_list[i] != NULL; i++) {
        if (resources->champion_list[i]->name)
            free(resources->champion_list[i]->name);
        if (resources->champion_list[i]->comment)
            free(resources->champion_list[i]->comment);
        if (resources->champion_list[i]->code)
            free(resources->champion_list[i]->code);
        if (resources->champion_list[i])
            free(resources->champion_list[i]);
    }
    if (resources->champion_list)
        free(resources->champion_list);
    if (resources->flags)
        free(resources->flags);
    free(resources);
}
