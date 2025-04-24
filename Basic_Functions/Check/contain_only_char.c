/*
** EPITECH PROJECT, 2025
** contain_only_char.c
** File description:
** check if the string contains only specified characters
*/

#include "my.h"

int contain_only_char(char *str, char *c)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (contain_char(c, str[i]) != 1)
            return 0;
    }
    return 1;
}
