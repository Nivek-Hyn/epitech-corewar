/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** print_winner_banner
*/

#include "project.h"

static void print_banner_box(WINDOW *win, int y, int x, int width)
{
    for (int row = 0; row < 5; row++)
        mvwprintw(win, y + row, x, "%*s", width, "");
    mvwhline(win, y, x, ACS_HLINE, width);
    mvwhline(win, y + 4, x, ACS_HLINE, width);
}

void print_winner_banner(resources_t *resources, graphical_t *graphical)
{
    champion_t *winner = graphical->winner;
    int index = 0;
    int width = 40;
    int attributes = A_BOLD;

    if (winner == NULL)
        return;
    index = champion_index(resources, winner->prog_number);
    if (graphical->rich_colors && index >= 0 && index < 4)
        attributes |= COLOR_PAIR(45 + index * 4);
    else if (index >= 0)
        attributes |= COLOR_PAIR(10 + index % 6);
    wattron(graphical->arena_win, attributes);
    print_banner_box(graphical->arena_win, 18, (97 - width) / 2, width);
    mvwprintw(graphical->arena_win, 19, (97 - 6) / 2, "WINNER");
    mvwprintw(graphical->arena_win, 21, (97 - my_strlen(winner->name)) / 2,
        "%s", winner->name);
    wattroff(graphical->arena_win, attributes);
}
