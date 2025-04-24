/*
** EPITECH PROJECT, 2024
** my_putchar.c
** File description:
** print a character
*/

#include "my.h"

void my_putchar_stderr(char c)
{
    write(2, &c, 1);
}
