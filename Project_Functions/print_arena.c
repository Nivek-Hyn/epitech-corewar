/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** print_arena
*/

#include "project.h"

void print_arena(resources_t *resources)
{
    char dest[3];

    for (int i = 0; i < MEM_SIZE; i++) {
        convert_char_to_hexa(resources->arena[i], dest);
        mega_write(1, "%s", dest);
    if (i > 0 && i % 32 == 0)
        mega_write(1, "\n");
    }
    mega_write(1, "\n");
}
