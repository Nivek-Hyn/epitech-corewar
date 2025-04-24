/*
** EPITECH PROJECT, 2025
** check_last_char.c
** File description:
** check if the last char is the chosen char
*/

#include "my.h"

int check_last_char(char *str, char c)
{
    int i = 0;

    if (!str || *str == '\0')
        return 0;
    for (i = 0; str[i + 1] != '\0'; i++) {
    }
    if (str[i] == c && str[i + 1] == '\0') {
        return 1;
    } else {
        return 0;
    }
}
