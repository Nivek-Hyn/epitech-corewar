/*
** EPITECH PROJECT, 2025
** check_delimiter_format.c
** File description:
** error handling for delimiter format
*/

#include "my.h"

int check_delimiter_format(char *str, char delimiter)
{
    int toggle = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == delimiter && toggle == 1)
            return -1;
        if (str[i] == delimiter && toggle == 0)
            toggle = 1;
        if (str[i + 1] == '\0' && toggle == 1)
            return -1;
        if (str[i] != delimiter)
            toggle = 0;
    }
    return 0;
}
