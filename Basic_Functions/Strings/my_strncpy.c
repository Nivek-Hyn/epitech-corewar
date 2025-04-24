/*
** EPITECH PROJECT, 2024
** my_strncpy.c
** File description:
** copy n characters of a string into another string
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (i = 0; src[i] != '\0' && i < n; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
