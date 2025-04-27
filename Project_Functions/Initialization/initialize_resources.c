/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** initialize_resources
*/

#include "project.h"

int initialize_resources(resources_t *resources)
{
    resources->champion_list = NULL;
    resources->nb_champion = 0;
    resources->flags = malloc(sizeof(flags_t));
    if (check_malloc(resources->flags, "flags: Malloc Failed.\n") == -1)
        return -1;
    resources->flags->dump = 0;
    resources->flags->n = 0;
    resources->flags->prog_number = 0;
    resources->flags->a = 0;
    resources->flags->load_address = -1;
    resources->nbr_cycle = 0;
    for (int i = 0; i < MEM_SIZE; i++)
        resources->arena[i] = 0;
    resources->arena[MEM_SIZE] = '\0';
    return 0;
}
