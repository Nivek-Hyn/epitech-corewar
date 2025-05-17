/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** print_stats
*/

#include "project.h"

void print_stats(resources_t *resources, graphical_t *graphical)
{
    werase(graphical->info_win);
    werase(graphical->params_win);
    werase(graphical->help_win);
    box(graphical->arena_win, 0, 0);
    box(graphical->info_win, 0, 0);
    box(graphical->params_win, 0, 0);
    box(graphical->help_win, 0, 0);
    print_info_graphical(graphical, resources);
    print_params_graphical(graphical, resources);
    print_help_graphical(graphical);
    wrefresh(graphical->arena_win);
    wrefresh(graphical->info_win);
    wrefresh(graphical->params_win);
    wrefresh(graphical->help_win);
}
