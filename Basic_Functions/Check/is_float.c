/*
** EPITECH PROJECT, 2025
** is_float.c
** File description:
** check if it's a float
*/

#include "my.h"

int is_float(char *str)
{
    int point_count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (i == 0 && str[i] == '-')
            continue;
        if (str[i] == '.')
            point_count++;
        if (str[i] != '.' && !is_digit(str[i]))
            return 0;
    }
    if (point_count == 1) {
        return 1;
    } else {
        return 0;
    }
}
