/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** Initialization
*/

#include "project.h"

void initialize_graphical(graphical_t *graphical)
{
    graphical->cycle = 0;
    graphical->cycle_to_die = CYCLE_TO_DIE;
    graphical->cycle_checker = 0;
    graphical->winner = NULL;
    graphical->c = 0;
    graphical->timeout_value = 10;
    graphical->paused = 0;
    graphical->game_running = 0;
    graphical->offset_y = 0;
    graphical->color_code = NULL;
    graphical->window = NULL;
    graphical->arena_win = NULL;
    graphical->info_win = NULL;
    graphical->params_win = NULL;
    graphical->help_win = NULL;
}

void initialize_ncurses(void)
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, FALSE);
    curs_set(0);
}

void initialize_windows(graphical_t *graphical)
{
    graphical->window = newwin(45, 150, 0, 0);
    graphical->arena_win = newwin(43, 97, 0, 0);
    graphical->info_win = newwin(16, 49, 0, 97);
    graphical->params_win = newwin(16, 49, 16, 97);
    graphical->help_win = newwin(11, 49, 32, 97);
    keypad(graphical->window, TRUE);
    nodelay(graphical->window, FALSE);
    keypad(graphical->arena_win, TRUE);
    nodelay(graphical->arena_win, FALSE);
    keypad(graphical->info_win, TRUE);
    nodelay(graphical->info_win, FALSE);
    keypad(graphical->params_win, TRUE);
    nodelay(graphical->params_win, FALSE);
    keypad(graphical->help_win, TRUE);
    nodelay(graphical->help_win, FALSE);
}
