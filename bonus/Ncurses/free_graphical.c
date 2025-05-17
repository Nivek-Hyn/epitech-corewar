/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** free_graphical
*/

#include "project.h"

void free_all_graphical(graphical_t *graphical)
{
    for (int i = 0; graphical->color_code &&
            graphical->color_code[i] != NULL; i++) {
        if (graphical->color_code[i] != NULL)
            free(graphical->color_code[i]);
    }
    if (graphical->color_code != NULL)
        free(graphical->color_code);
    delwin(graphical->window);
    delwin(graphical->arena_win);
    delwin(graphical->info_win);
    delwin(graphical->params_win);
    delwin(graphical->help_win);
    free(graphical);
}
