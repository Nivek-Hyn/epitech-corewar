/*
** EPITECH PROJECT, 2025
** char_to_string.c
** File description:
** transform a character into a string and return it
*/

#include "my.h"

char *char_to_string(char c)
{
    char *string = malloc(sizeof(char) * 2);

    if (!string)
        return NULL;
    string[0] = c;
    string[1] = '\0';
    return string;
}
