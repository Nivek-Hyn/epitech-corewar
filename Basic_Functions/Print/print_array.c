/*
** EPITECH PROJECT, 2025
** print_array.c
** File description:
** print each index in an array
*/

#include "my.h"

void print_array(char **array, char c)
{
    for (int i = 0; array[i] != NULL; i++) {
        mega_write(STDOUT_FILENO, "%s%c", array[i], c);
    }
}
