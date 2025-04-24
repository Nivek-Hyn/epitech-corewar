/*
** EPITECH PROJECT, 2024
** mini_printf.c
** File description:
** printf but with minimal flags
*/

#include "my.h"

static void flag(char c, va_list args)
{
    switch (c) {
    case 'c':
        my_putchar(va_arg(args, int));
        break;
    case 's':
        my_putstr(va_arg(args, char *));
        break;
    case 'd':
    case 'i':
        my_putnbr(va_arg(args, int));
        break;
    case '%':
        my_putchar('%');
        break;
    default:
        break;
    }
}

void mini_printf(const char *format, ...)
{
    int i = 0;
    va_list args;

    va_start(args, *format);
    for (i = 0; format[i] != '\0'; i++) {
        if (format[i] != '%') {
            my_putchar(format[i]);
        }
        if (format[i] == '%') {
            flag(format[i + 1], args);
            i++;
        }
    }
    va_end(args);
}
