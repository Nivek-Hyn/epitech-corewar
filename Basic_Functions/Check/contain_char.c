/*
** EPITECH PROJECT, 2025
** contain_char.c
** File description:
** check if the string contains a specific character.
*/

#include "my.h"

int contain_char(char *str, char c)
{
    if (!str)
        return 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return 1;
    }
    return 0;
}
