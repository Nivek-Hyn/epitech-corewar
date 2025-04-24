/*
** EPITECH PROJECT, 2025
** count_until_delim.c
** File description:
** count and return the number of character counted till a delimiter
*/

#include "my.h"

int count_until_delim(char *str, char *delim)
{
    int count = 0;
    int delim_len = 0;

    if (!str || !delim)
        return 0;
    delim_len = (*delim == '\0') ? 1 : my_strlen(delim);
    for (int i = 0; my_strncmp(&str[i], delim, delim_len) != 0
        && str[i] != '\0'; i++) {
        count++;
    }
    return count;
}
