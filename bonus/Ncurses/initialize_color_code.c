/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** initialize_color_code
*/

#include "project.h"

void init_dark_color(void)
{
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_BLUE, COLOR_BLACK);
    init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(7, COLOR_CYAN, COLOR_BLACK);
    init_pair(8, COLOR_BLACK, COLOR_BLACK);
    init_pair(9, COLOR_BLACK, COLOR_WHITE);
}

void init_normal_color(void)
{
    init_pair(10, COLOR_BLACK, COLOR_RED);
    init_pair(11, COLOR_BLACK, COLOR_GREEN);
    init_pair(12, COLOR_BLACK, COLOR_YELLOW);
    init_pair(13, COLOR_BLACK, COLOR_BLUE);
    init_pair(14, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(15, COLOR_BLACK, COLOR_CYAN);
}

void init_light_color(void)
{
    init_pair(16, COLOR_WHITE, COLOR_WHITE);
    init_pair(17, COLOR_BLACK, COLOR_WHITE);
    init_pair(18, COLOR_RED, COLOR_WHITE);
    init_pair(19, COLOR_GREEN, COLOR_WHITE);
    init_pair(20, COLOR_YELLOW, COLOR_WHITE);
    init_pair(21, COLOR_BLUE, COLOR_WHITE);
    init_pair(22, COLOR_MAGENTA, COLOR_WHITE);
    init_pair(23, COLOR_CYAN, COLOR_WHITE);
}

void initialize_color_code(resources_t *resources, graphical_t *graphical)
{
    start_color();
    init_dark_color();
    init_normal_color();
    init_light_color();
    initialize_rich_colors(graphical);
    graphical->color_code = malloc(sizeof(color_code_t *) *
        (resources->nb_champion + 1));
    graphical->color_code[resources->nb_champion] = NULL;
    for (int i = 0; i < resources->nb_champion; i++) {
        graphical->color_code[i] = malloc(sizeof(color_code_t));
        graphical->color_code[i]->color = i + 2;
        graphical->color_code[i]->prog_number =
            resources->champion_list[i]->prog_number;
    }
}
