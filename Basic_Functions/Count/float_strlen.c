/*
** EPITECH PROJECT, 2025
** float_strlen.c
** File description:
** return the lenght of a float string
*/

#include "my.h"

int float_strlen(char *float_str)
{
    int len = 0;
    int dot_found = 0;

    if (!float_str)
        return 0;
    while (is_digit(float_str[len]) ||
        (float_str[len] == '.' && !dot_found)) {
        if (float_str[len] == '.')
            dot_found = 1;
        len++;
    }
    return len;
}
