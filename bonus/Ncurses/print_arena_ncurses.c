/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** print_arena_ncurses
*/

#include "project.h"

void set_color(graphical_t *graphical, int owner, int *color_pair)
{
    for (int j = 0; owner != -1 && graphical->color_code[j]; j++) {
        if (graphical->color_code[j]->prog_number == owner) {
            *color_pair = graphical->color_code[j]->color;
            break;
        }
    }
}

void print_arena_ncurses(resources_t *resources, graphical_t *graphical)
{
    char dest[3];
    int start_line = graphical->offset_y;
    int end_line = start_line + 41;
    int attributes = 0;
    int i = 0;

    for (int y = start_line; y < end_line && y < 192; y++) {
        for (int x = 0; x < 32; x++) {
            i = y * 32 + x;
            convert_char_to_hexa(resources->arena[i], dest);
            attributes = cell_attributes(resources, graphical, i);
            wattron(graphical->arena_win, attributes);
            mvwprintw(graphical->arena_win,
                (y - start_line) + 1, x * 3 + 1, "%s", dest);
            wattroff(graphical->arena_win, attributes);
        }
    }
    print_winner_banner(resources, graphical);
}
