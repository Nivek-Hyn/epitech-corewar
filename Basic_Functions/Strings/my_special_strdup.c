/*
** EPITECH PROJECT, 2025
** my_special_strdup.c
** File description:
** duplicate and return a selected part of a string
*/

#include "my.h"

char *my_special_strdup(int i, char *str, char *delimiter)
{
    int len = my_special_strlen(i, str, delimiter);
    char *result = malloc(sizeof(char) * (len + 1));

    if (!result)
        return NULL;
    if (!str) {
        free(result);
        return NULL;
    }
    for (; contain_char(delimiter, str[i]) != 1 && str[i] != '\0'; i++) {
        result[i] = str[i];
    }
    result[i] = '\0';
    return result;
}
