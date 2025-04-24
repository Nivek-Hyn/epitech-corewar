/*
** EPITECH PROJECT, 2025
** check_malloc.c
** File description:
** check if the malloc succeeded
*/

#include "my.h"

int check_malloc(void *data, char *error_text_display)
{
    if (!data) {
        if (!error_text_display || *error_text_display == '\0') {
            mega_write(STDERR_FILENO, "Malloc failed.\n");
            return -1;
        }
        if (error_text_display) {
            mega_write(STDERR_FILENO, "%s", error_text_display);
            return -1;
        }
    }
    return 0;
}
