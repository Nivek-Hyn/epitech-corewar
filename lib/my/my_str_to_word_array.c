/*
** EPITECH PROJECT, 2024
** my_isneg
** File description:
** my_isneg.c
*/

#include "../../include/corewar.h"

char **returner(int k, int j, char **arrays)
{
    arrays[k][j] = '\0';
    arrays[k + 1] = NULL;
    return arrays;
}

char **my_str_to_word_array(char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char **arrays = malloc(sizeof(char *) * ((my_strlen(str) / 2) + 3));

    arrays[k] = malloc(sizeof(char) * (my_strlen(str) + 1));
    while (str[i] != '\0') {
        if ((str[i] == ' ' || str[i] == '\t') && j > 0) {
            arrays[k][j] = '\0';
            k++;
            j = 0;
            arrays[k] = malloc(sizeof(char) * (my_strlen(str) + 1));
        } else {
            arrays[k][j] = str[i];
            j++;
        }
        i++;
    }
    returner(k, j, arrays);
}

void handle_hastag2(int **i, int len, char *str)
{
    while (str[*(*i)] != '\n') {
        if (*(*i) >= len)
            break;
        (*(*i))++;
    }
}

void handle_hastag(char *str, int *i)
{
    int len = my_strlen(str);

    if (str[*i] == '#' && str[*i + 1] != '#' && str[*i - 1] != '#') {
        handle_hastag2(&i, len, str);
    }
}

char **my_str_to_word_array_delim(char *str, char delim)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char **arrays = malloc(sizeof(char *) * ((my_strlen(str) / 2) + 3));

    arrays[k] = malloc(sizeof(char) * (my_strlen(str) + 1));
    while (str[i] != '\0') {
        handle_hastag(str, &i);
        if ((str[i] == delim || str[i] == '\n') && j > 0) {
            arrays[k][j] = '\0';
            k++;
            j = 0;
            arrays[k] = malloc(sizeof(char) * (my_strlen(str) + 1));
        } else {
            arrays[k][j] = str[i];
            j++;
        }
        i++;
    }
    returner(k, j, arrays);
}
