/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** run_graphical_corewar
*/

#include "project.h"
#include <ncurses.h>

void game_manager(graphical_t *graphical)
{
    wtimeout(graphical->arena_win, graphical->timeout_value);
    graphical->c = wgetch(graphical->arena_win);
}

void menu_manager(graphical_t *graphical)
{
    wrefresh(graphical->window);
    wtimeout(graphical->window, 0);
    graphical->c = wgetch(graphical->window);
}

void graphical_corewar(resources_t *resources, graphical_t *graphical)
{
    key_input_manager(resources, graphical);
    if (graphical->game_running == 1) {
        print_stats(resources, graphical);
        print_arena_ncurses(resources, graphical);
        if (graphical->paused == 0)
            corewar_system(resources, graphical);
        game_manager(graphical);
    } else if (graphical->game_running == 0) {
        show_menu(graphical);
        menu_manager(graphical);
    }
    refresh();
}

void run_graphical_corewar(resources_t *resources)
{
    graphical_t *graphical = malloc(sizeof(graphical_t));

    initialize_graphical(graphical);
    initialize_ncurses();
    initialize_windows(graphical);
    initialize_color_code(resources, graphical);
    show_menu(graphical);
    while (graphical->c != 'q' && graphical->c != 27)
        graphical_corewar(resources, graphical);
    free_all_graphical(graphical);
    endwin();
}
