/*
** EPITECH PROJECT, 2024
** my_strlen.c
** File description:
** return number of character
*/

#include "my.h"

int my_strlen(char *str)
{
    int i = 0;

    if (!str)
        return 0;
    for (i = 0; str[i] != '\0'; i++) {
    }
    return i;
}
