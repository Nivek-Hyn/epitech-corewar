/*
** EPITECH PROJECT, 2025
** replace_last_char.c
** File description:
** replace the last char of a string by the given one
*/

#include "my.h"

void replace_last_char(char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i + 1] == '\0')
            str[i] = c;
    }
}
