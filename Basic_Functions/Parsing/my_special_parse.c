/*
** EPITECH PROJECT, 2025
** my_special_parse.c
** File description:
** return an array after parsing using strtok
*/

#include "my.h"

static void fill_array(char *str, char *separator, char **array,
    char *(*strtok_func)(char *str, char *delim, char *token, int *i))
{
    char *token = NULL;
    int i = 0;
    int j = 0;

    token = strtok_func(str, separator, token, &j);
    while (token) {
        array[i] = my_strdup(token);
        i++;
        token = strtok_func(str, separator, token, &j);
    }
}

char **my_special_parse(char *str, char *separator,
    char *(*strtok_func)(char *str, char *delim, char *token, int *i))
{
    char **array = NULL;
    char *token = NULL;
    int i = 0;
    int j = 0;

    if (!str)
        return NULL;
    token = strtok_func(str, separator, token, &j);
    while (token) {
        i++;
        token = strtok_func(str, separator, token, &j);
    }
    array = malloc(sizeof(char *) * (i + 1));
    if (!array)
        return NULL;
    array[i] = NULL;
    fill_array(str, separator, array, strtok_func);
    return array;
}
