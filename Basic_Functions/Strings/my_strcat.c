/*
** EPITECH PROJECT, 2024
** my_strcat.c
** File description:
** concatenate 2 string in a already allocated string
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;

    if (!dest || !src)
        return NULL;
    for (i = 0; dest[i] != '\0'; i++) {
    }
    for (j = 0; src[j] != '\0'; j++) {
        dest[i] = src[j];
        i++;
    }
    dest[i] = src[j];
    return dest;
}
