/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** print_stats
*/

#include "project.h"

void print_help_graphical(graphical_t *graphical)
{
    mvwprintw(graphical->help_win, 1, (49 / 2) - (4 / 2), "HELP");
    mvwprintw(graphical->help_win, 3, 1, "RIGHT\t-\tIncrease 10 ms from delay");
    mvwprintw(graphical->help_win, 4, 1, "LEFT\t-\tDecrease 10 ms from delay");
    mvwprintw(graphical->help_win, 5, 1, "UP\t-\tScroll up in the arena");
    mvwprintw(graphical->help_win, 6, 1, "DOWN\t-\tScroll down in the arena");
    mvwprintw(graphical->help_win, 7, 1, "SPACE\t-\tPause/Resume");
    mvwprintw(graphical->help_win, 9, 1, "Q\t-\tQuit");
}

void print_params_graphical(graphical_t *graphical, resources_t *resources)
{
    mvwprintw(graphical->params_win, 1, (49 / 2) - (6 / 2), "PARAMS");
    mvwprintw(graphical->params_win, 3, 1, "Cycle\t:\t%d", graphical->cycle);
    mvwprintw(graphical->params_win, 4, 1, "Delay\t:\t%d ms",
        graphical->timeout_value);
    mvwprintw(graphical->params_win, 6, 1, "Total lives\t:\t%d",
    resources->total_lives);
    mvwprintw(graphical->params_win, 7, 1, "Cycle to die\t:\t%d",
        graphical->cycle_to_die);
    mvwprintw(graphical->params_win, 8, 1, "Cycle delta\t:\t%d", CYCLE_DELTA);
    mvwprintw(graphical->params_win, 9, 1, "Running\t:\t%s",
        (graphical->paused == 0) ? "True" : "False");
    mvwprintw(graphical->params_win, 11, 1, "Winner\t:\t%s",
        (graphical->winner == NULL) ? "None" : graphical->winner->name);
}

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
