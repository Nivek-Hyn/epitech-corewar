/*
** EPITECH PROJECT, 2025
** count_lines.c
** File description:
** return number of lines
*/

#include "my.h"

int count_lines(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            count++;
        if (str[i] != '\n' && str[i + 1] == '\0')
            count++;
    }
    return count;
}
