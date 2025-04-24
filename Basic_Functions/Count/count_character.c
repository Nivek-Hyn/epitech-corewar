/*
** EPITECH PROJECT, 2025
** count_character.c
** File description:
** return the number of times a given character appears
*/

#include "my.h"

int count_character(char *str, char c)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            count++;
    }
    return count;
}
