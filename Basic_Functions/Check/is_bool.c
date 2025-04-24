/*
** EPITECH PROJECT, 2025
** is_bool.c
** File description:
** check if it's a bool
*/

#include "my.h"

int is_bool(char *str)
{
    char *str_copy = my_strdup(str);

    str_copy = my_strlowcase(str_copy);
    if (my_strcmp(str_copy, "true") == 0 ||
        my_strcmp(str_copy, "false") == 0) {
        free(str_copy);
        return 1;
    } else {
        free(str_copy);
        return 0;
    }
}
