/*
** EPITECH PROJECT, 2025
** array_to_string.c
** File description:
** transform an array of words into a string
*/

#include "my.h"

static void create_string(char **array, char *string, char *separator)
{
    for (int i = 0; array[i] != NULL; i++) {
        if (array[i])
            string = my_strcat(string, array[i]);
        if (array[i] && separator && array[i + 1] != NULL)
            string = my_strcat(string, separator);
    }
}

char *array_to_string(char **array, char *separator)
{
    char *string = NULL;
    int len = 0;

    if (!array)
        return NULL;
    for (int i = 0; array[i] != NULL; i++) {
        if (array[i])
            len += my_strlen(array[i]);
    }
    len = (len + ((array_len(array) - 1) * my_strlen(separator)));
    string = malloc(sizeof(char) * (len + 1));
    if (!string)
        return NULL;
    string[0] = '\0';
    create_string(array, string, separator);
    return string;
}
