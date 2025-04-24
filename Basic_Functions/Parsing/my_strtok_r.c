/*
** EPITECH PROJECT, 2025
** my_strtok_r.c
** File description:
** parse a string using a delimiter and return the string part
*/

#include "my.h"

static int my_strtok_r_check_quote(char *str, char *delim, int *i,
    int *toggle)
{
    if (contain_char(delim, '\"') != 1) {
        if (*toggle == 0 && str[*i] == '\"') {
            *toggle = 1;
            return 1;
        }
        if (*toggle == 1 && str[*i] == '\"') {
            *toggle = 0;
            return 1;
        }
    }
    return 0;
}

static char *fill_token(char *str, char *delim, int count, int *i)
{
    char *token = malloc(sizeof(char) * (count + 1));
    int toggle = 0;

    if (!token)
        return NULL;
    token[count] = '\0';
    for (int j = 0; (toggle == 0 && my_strncmp(&str[*i], delim,
        my_strlen(delim)) != 0 && str[*i] != '\0') || (toggle == 1 &&
        str[*i] != '\0'); (*i)++) {
        if (my_strtok_r_check_quote(str, delim, i, &toggle) != 1) {
            token[j] = str[*i];
            j++;
        }
    }
    if (str[*i] != '\0')
        (*i) += my_strlen(delim);
    return token;
}

static int count_token(char *str, char *delim, int *i)
{
    int count = 0;
    int toggle = 0;

    for (int j = *i; (toggle == 0 &&
        my_strncmp(&str[j], delim, my_strlen(delim)) != 0 &&
        str[j] != '\0') || (toggle == 1 && str[j] != '\0'); j++) {
        if (my_strtok_r_check_quote(str, delim, &j, &toggle) != 1)
            count++;
    }
    return count;
}

char *my_strtok_r(char *str, char *delim, char *token, int *i)
{
    int count = 0;

    if (!str)
        return NULL;
    while (my_strncmp(str, delim, my_strlen(delim)) == 0)
        (*i) += my_strlen(delim);
    if (str[*i] == '\0') {
        if (token)
            free(token);
        return NULL;
    }
    count = count_token(str, delim, i);
    if (token)
        free(token);
    return fill_token(str, delim, count, i);
}
