/*
** EPITECH PROJECT, 2025
** is_int.c
** File description:
** check if it's an int
*/

#include "my.h"

int is_int(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (i == 0 && str[i] == '-')
            continue;
        if (!is_digit(str[i]))
            return 0;
    }
    return 1;
}
