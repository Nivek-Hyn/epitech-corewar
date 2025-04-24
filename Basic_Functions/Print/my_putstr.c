/*
** EPITECH PROJECT, 2024
** my_putstr.c
** File description:
** print a string
*/

#include "my.h"

void my_putstr(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
}
