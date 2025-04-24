/*
** EPITECH PROJECT, 2025
** my_parse.c
** File description:
** takes multiple delimiters, parse multiple parts and returns an array
*/

#include "my.h"

static char **fill_array(char **array, char *str,
    char *delimiter, int array_len)
{
    char *token = NULL;
    int i_delims = 0;
    int i_strtok = 0;

    for (int i = 0; i < array_len && delimiter[i_delims] != '\0'; i++) {
        array[i] = my_strtok(str, char_to_string(delimiter[i_delims]),
            token, &i_strtok);
        i_delims++;
    }
    return array;
}

static int get_parts_nbr(char *str, char *delimiter)
{
    int i = 0;
    int i_delims = 0;
    int count = 0;
    int toggle = 1;

    while (str[i] != '\0') {
        if (str[i] == delimiter[i_delims] && toggle == 0) {
            i++;
            count++;
            i_delims++;
            toggle = 1;
        } else {
            i++;
        }
        if (str[i] != delimiter[i_delims] && toggle == 1)
            toggle = 0;
    }
    if (count == 0)
        return 1;
    return count;
}

char **my_parse_select(char *str, char *delimiter)
{
    char **array = NULL;
    int array_len = 0;

    if (!str || *str == '\0')
        return NULL;
    if (delimiter && *delimiter != '\0') {
        array_len = get_parts_nbr(str, delimiter);
    } else {
        array_len = 1;
    }
    array = malloc(sizeof(char *) * (array_len + 1));
    if (!array)
        return NULL;
    array[array_len] = NULL;
    if (delimiter && *delimiter != '\0') {
        array = fill_array(array, str, delimiter, array_len);
    } else {
        array[0] = my_strdup(str);
    }
    return array;
}
