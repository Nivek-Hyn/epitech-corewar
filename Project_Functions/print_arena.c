/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** print_arena
*/

#include "project.h"

int get_color_code(int index)
{
    return 16 + (index * 47) % 216;
}

void print_arena(resources_t *resources)
{
    char dest[3];
    char *white_color_mode = "\033[0m";

    for (int i = 0; i < MEM_SIZE; i++) {
        convert_char_to_hexa(resources->arena[i], dest);
        if (resources->owner[i] == -1) {
            mega_write(1, "%s%s", white_color_mode, dest);
        } else {
            mega_write(1, "\033[38;5;%dm%s",
                get_color_code(resources->owner[i]), dest);
        }
        if (i > 0 && i % 32 == 0)
            mega_write(1, "%s\n", white_color_mode);
    }
    mega_write(1, "%s\n", white_color_mode);
}
