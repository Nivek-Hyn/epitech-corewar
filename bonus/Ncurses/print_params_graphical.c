/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** print_params_graphical
*/

#include "project.h"

void print_winner(graphical_t *graphical)
{
    int color_pair = 1;

    mvwprintw(graphical->params_win, 11, 1, "Winner\t:\t");
    if (graphical->winner != NULL) {
        set_color(graphical,
            graphical->winner->prog_number, &color_pair);
        wattron(graphical->params_win, COLOR_PAIR(color_pair));
        mvwprintw(graphical->params_win, 11, 16, "%s",
            graphical->winner->name);
        wattroff(graphical->params_win, COLOR_PAIR(color_pair));
    } else {
        mvwprintw(graphical->params_win, 11, 16, "None");
    }
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
    print_winner(graphical);
}
