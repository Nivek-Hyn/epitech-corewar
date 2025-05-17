/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** key_input_manager
*/

#include "project.h"

void space_key_input_manager(graphical_t *graphical)
{
    if (graphical->c == ' ' && graphical->paused == 0) {
        graphical->tmp_timeout_value = graphical->timeout_value;
        graphical->timeout_value = 0;
        graphical->paused = 1;
    } else if (graphical->c == ' ' && graphical->paused == 1) {
        graphical->timeout_value = graphical->tmp_timeout_value;
        graphical->paused = 0;
    }
}

void arrows_key_input_manager(graphical_t *graphical)
{
    if (graphical->c == 260 && graphical->paused != 1) {
        if (graphical->timeout_value != 0)
            graphical->timeout_value -= 10;
    } else if (graphical->c == 261 && graphical->paused != 1) {
        graphical->timeout_value += 10;
    }
    if (graphical->c == 258 && graphical->offset_y < 192) {
            graphical->offset_y++;
    } else if (graphical->c == 259 && graphical->offset_y > 0) {
        graphical->offset_y--;
    }
}

void when_game_starts(resources_t *resources, graphical_t *graphical)
{
    clear();
    wclear(graphical->window);
    wclear(graphical->arena_win);
    wclear(graphical->info_win);
    wclear(graphical->params_win);
    wclear(graphical->help_win);
    wrefresh(graphical->window);
    wrefresh(graphical->arena_win);
    wrefresh(graphical->info_win);
    wrefresh(graphical->params_win);
    wrefresh(graphical->help_win);
    box(graphical->arena_win, 0, 0);
    box(graphical->info_win, 0, 0);
    box(graphical->params_win, 0, 0);
    box(graphical->help_win, 0, 0);
}

void key_input_manager(resources_t *resources, graphical_t *graphical)
{
    if (graphical->c == 's' && graphical->game_running == 0) {
        graphical->game_running = 1;
        when_game_starts(resources, graphical);
    }
    arrows_key_input_manager(graphical);
    space_key_input_manager(graphical);
}
