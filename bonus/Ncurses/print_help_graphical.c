/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** print_help_graphical
*/

#include "project.h"

void print_help_graphical(graphical_t *graphical)
{
    mvwprintw(graphical->help_win, 1, (49 / 2) - (4 / 2), "HELP");
    mvwprintw(graphical->help_win, 3, 1,
        "RIGHT\t-\tIncrease 10 ms from delay");
    mvwprintw(graphical->help_win, 4, 1, "LEFT\t-\tDecrease 10 ms from delay");
    mvwprintw(graphical->help_win, 5, 1, "UP\t-\tScroll up in the arena");
    mvwprintw(graphical->help_win, 6, 1, "DOWN\t-\tScroll down in the arena");
    mvwprintw(graphical->help_win, 7, 1, "SPACE\t-\tPause/Resume");
    mvwprintw(graphical->help_win, 9, 1, "Q\t-\tQuit");
}
