/*
** EPITECH PROJECT, 2025
** is_number.c
** File description:
** check if it's a number
*/

#include "my.h"

int is_number(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (i == 0 && str[i] == '-')
            continue;
        if (!is_digit(str[i]))
            return 0;
    }
    return 1;
}
