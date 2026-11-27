/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** print_info_graphical
*/

#include "project.h"

void print_info_player_two(graphical_t *graphical, resources_t *resources,
    int champion_index, int y)
{
    int color_pair = 1;

    set_color(graphical,
        resources->champion_list[champion_index]->prog_number, &color_pair);
    wattron(graphical->info_win, COLOR_PAIR(color_pair));
    mvwprintw(graphical->info_win, y, 30, "Champion %d (%s)",
        resources->champion_list[champion_index]->prog_number,
        resources->champion_list[champion_index]->name);
    wattroff(graphical->info_win, COLOR_PAIR(color_pair));
}

void print_info_player(graphical_t *graphical, resources_t *resources,
    int champion_index, int y)
{
    print_champion_stats(graphical, resources, champion_index, y);
}

void print_info_graphical_two(graphical_t *graphical, resources_t *resources)
{
    if (resources->champion_list[6] == NULL)
        return;
    print_info_player_two(graphical, resources, 6, 3);
    if (resources->champion_list[7] == NULL)
        return;
    print_info_player_two(graphical, resources, 7, 5);
    if (resources->champion_list[8] == NULL)
        return;
    print_info_player_two(graphical, resources, 8, 7);
    if (resources->champion_list[9] == NULL)
        return;
    print_info_player_two(graphical, resources, 9, 9);
    if (resources->champion_list[10] == NULL)
        return;
    print_info_player_two(graphical, resources, 10, 11);
    if (resources->champion_list[11] == NULL)
        return;
    print_info_player_two(graphical, resources, 11, 13);
}

void print_info_graphical(graphical_t *graphical, resources_t *resources)
{
    mvwprintw(graphical->info_win, 1, (49 / 2) - (4 / 2), "INFO");
    if (resources->champion_list[0] == NULL) {
        mvwprintw(graphical->info_win, 3, 1, "No champion loaded");
        return;
    }
    print_info_player(graphical, resources, 0, 3);
    if (resources->champion_list[1] == NULL)
        return;
    print_info_player(graphical, resources, 1, 5);
    if (resources->champion_list[2] == NULL)
        return;
    print_info_player(graphical, resources, 2, 7);
    if (resources->champion_list[3] == NULL)
        return;
    print_info_player(graphical, resources, 3, 9);
    if (resources->champion_list[4] == NULL)
        return;
    print_info_player(graphical, resources, 4, 11);
    if (resources->champion_list[5] == NULL)
        return;
    print_info_player(graphical, resources, 5, 13);
    return print_info_graphical_two(graphical, resources);
}
