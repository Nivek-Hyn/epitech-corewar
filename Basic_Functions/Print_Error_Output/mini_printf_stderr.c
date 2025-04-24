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
        my_putchar_stderr(va_arg(args, int));
        break;
    case 's':
        my_putstr_stderr(va_arg(args, char *));
        break;
    case 'd':
    case 'i':
        my_putnbr_stderr(va_arg(args, int));
        break;
    case '%':
        my_putchar_stderr('%');
        break;
    default:
        break;
    }
}

void mini_printf_stderr(const char *format, ...)
{
    int i = 0;
    va_list args;

    va_start(args, *format);
    for (i = 0; format[i] != '\0'; i++) {
        if (format[i] != '%') {
            my_putchar_stderr(format[i]);
        }
        if (format[i] == '%') {
            flag(format[i + 1], args);
            i++;
        }
    }
    va_end(args);
}
