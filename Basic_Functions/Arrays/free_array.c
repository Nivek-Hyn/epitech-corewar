/*
** EPITECH PROJECT, 2025
** free_array.c
** File description:
** free array
*/

#include "my.h"

void free_array(char **array)
{
    if (!array)
        return;
    for (int i = 0; array[i] != NULL; i++) {
        if (array[i])
            free(array[i]);
    }
    free(array);
}
