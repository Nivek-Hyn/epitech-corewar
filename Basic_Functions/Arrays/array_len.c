/*
** EPITECH PROJECT, 2025
** array_len.c
** File description:
** return array size
*/

#include "my.h"

int array_len(char **array)
{
    int count = 0;

    if (!array)
        return 0;
    for (int i = 0; array[i] != NULL; i++) {
        count++;
    }
    return count;
}
