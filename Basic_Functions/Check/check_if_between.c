/*
** EPITECH PROJECT, 2025
** check_if_between.c
** File description:
** check if the string is between chosen char
*/

#include "my.h"

int check_if_between(char *str, char c)
{
    if (!str)
        return 0;
    if (str[0] != c)
        return 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != c && str[i + 1] == '\0')
            return 0;
    }
    return 1;
}
