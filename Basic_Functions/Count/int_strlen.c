/*
** EPITECH PROJECT, 2025
** int_strlen.c
** File description:
** return the lenght of an int string
*/

#include "my.h"

int int_strlen(char *int_str)
{
    int len = 0;

    if (!int_str)
        return 0;
    while (is_digit(int_str[len] || (len == 0 && int_str[0] == '-')))
        len++;
    return len;
}
