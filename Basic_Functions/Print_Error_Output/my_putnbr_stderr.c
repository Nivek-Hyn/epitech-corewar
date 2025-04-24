/*
** EPITECH PROJECT, 2024
** my_putnbr.c
** File description:
** print a number
*/

#include "my.h"

void my_putnbr_stderr(int nb)
{
    if (nb < 0) {
        my_putchar_stderr('-');
        nb = -nb;
    }
    if (nb >= 10)
        my_putnbr_stderr(nb / 10);
    my_putchar_stderr((nb % 10) + '0');
}
