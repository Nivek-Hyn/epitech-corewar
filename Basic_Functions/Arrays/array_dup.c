/*
** EPITECH PROJECT, 2025
** array_dup.c
** File description:
** duplicate an array and return it
*/

#include "my.h"

char **array_dup(char **array)
{
    int i = array_len(array);
    char **new_array = malloc(sizeof(char *) * (i + 1));

    if (!array || !new_array)
        return NULL;
    for (int j = 0; j < i; j++) {
        new_array[j] = my_strdup(array[j]);
        if (!new_array[j]) {
            free_array(new_array);
            return NULL;
        }
    }
    new_array[i] = NULL;
    return new_array;
}
