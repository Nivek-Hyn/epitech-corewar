/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** show_menu
*/

#include "project.h"

void print_big_title(WINDOW *win, int start_y, int start_x)
{
    int fd = open("bonus/Ncurses/Corewar.txt", O_RDONLY);
    int size = file_size("bonus/Ncurses/Corewar.txt");
    char *buffer = malloc(size + 1);
    char **lines = NULL;

    read(fd, buffer, size);
    buffer[size] = '\0';
    lines = my_parse(buffer, "\n");
    for (int i = 0; lines[i] != NULL; i++) {
        mvwprintw(win, start_y + i, start_x, "%s", lines[i]);
    }
    close(fd);
    free_array(lines);
    free(buffer);
}

void show_menu(graphical_t *graphical)
{
    box(graphical->window, 0, 0);
    print_big_title(graphical->window, 1, 75 - (42 / 2));
    mvwprintw(graphical->window, (50 / 2), 75 - (33 / 2),
        "Press 's' to START, 'q' to quit.");
}
