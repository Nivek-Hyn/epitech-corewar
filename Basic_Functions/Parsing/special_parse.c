/*
** EPITECH PROJECT, 2025
** special_parse.c
** File description:
** return an array after parsing using strtok
*/

#include "my.h"
#include "string.h"

static void fill_array(char *str, const char *separator, char **array)
{
    char *token = NULL;
    char *str_copy = my_strdup(str);
    int i = 0;

    token = strtok(str_copy, separator);
    while (token) {
        array[i] = my_strdup(token);
        i++;
        token = strtok(NULL, separator);
    }
    if (str_copy)
        free(str_copy);
}

char **special_parse(char *str, const char *separator)
{
    char **array = NULL;
    char *token = NULL;
    char *str_copy = my_strdup(str);
    int i = 0;

    if (!str)
        return NULL;
    token = strtok(str_copy, separator);
    while (token) {
        i++;
        token = strtok(NULL, separator);
    }
    array = malloc(sizeof(char *) * (i + 1));
    if (!array)
        return NULL;
    array[i] = NULL;
    fill_array(str, separator, array);
    if (str_copy)
        free(str_copy);
    return array;
}
