/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** my.h
*/

#include "my.h"

int my_atoi(char *str)
{
    int result = 0;
    int sign = 1;

    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+') {
        str++;
    }
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }
    return sign * result;
}
