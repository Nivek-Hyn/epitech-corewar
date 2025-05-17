/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** print_info_graphical
*/

#include "project.h"

void print_info_player(graphical_t *graphical, resources_t *resources,
    int champion_index, int y)
{
    int color_pair = 1;

    set_color(graphical,
        resources->champion_list[champion_index]->prog_number, &color_pair);
    wattron(graphical->info_win, COLOR_PAIR(color_pair));
    mvwprintw(graphical->info_win, y, 1, "Champion %d (%s)",
        resources->champion_list[champion_index]->prog_number,
        resources->champion_list[champion_index]->name);
    wattroff(graphical->info_win, COLOR_PAIR(color_pair));
}

void print_info_graphical(graphical_t *graphical, resources_t *resources)
{
    mvwprintw(graphical->info_win, 1, (49 / 2) - (4 / 2), "INFO");
    print_info_player(graphical, resources, 0, 3);
    print_info_player(graphical, resources, 1, 5);
    print_info_player(graphical, resources, 2, 7);
    print_info_player(graphical, resources, 3, 9);
}
