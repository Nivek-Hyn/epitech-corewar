/*
** EPITECH PROJECT, 2024
** my_strncat.c
** File description:
** concatenate n characters of a string into another string
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int j = 0;

    if (!dest || !src)
        return NULL;
    for (i = 0; dest[i] != '\0'; i++) {
    }
    for (j = 0; src[j] != '\0' && j < nb; j++) {
        dest[i] = src[j];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
