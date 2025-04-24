/*
** EPITECH PROJECT, 2025
** error_gesting.c
** File description:
** error gestion for A-maze-ed
*/

#include "my.h"

char *my_strchr(const char *s, int c)
{
    while (*s != '\0') {
        if (*s == c) {
            return (char *)s;
        }
        s++;
    }
    return NULL;
}
