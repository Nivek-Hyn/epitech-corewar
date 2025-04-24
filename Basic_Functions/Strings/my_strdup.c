/*
** EPITECH PROJECT, 2024
** my_strdup.c
** File description:
** duplicate a string and return it
*/

#include "my.h"

char *my_strdup(char *str)
{
    char *result = malloc(sizeof(char) * my_strlen(str) + 1);
    int i = 0;

    if (!result)
        return NULL;
    if (!str) {
        free(result);
        return NULL;
    }
    for (; str[i] != '\0'; i++) {
        result[i] = str[i];
    }
    result[i] = '\0';
    return result;
}
