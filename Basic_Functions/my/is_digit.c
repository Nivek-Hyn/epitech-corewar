/*
** EPITECH PROJECT, 2024
** is_digit.c
** File description:
** verif sic'est  un nombre
*/

#include "../../include/corewar.h"

int is_digit(const char *str)
{
    int i = 0;

    if (str[0] == '\0')
        return 0;
    if (str[i] == '-') {
        i++;
    }
    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}
