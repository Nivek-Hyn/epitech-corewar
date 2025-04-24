/*
** EPITECH PROJECT, 2025
** my_special_strcat.c
** File description:
** concatenate each chosen part of two strings together
*/

#include "my.h"

static char *concatenate(char *str1, int n1, char *str2, int n2)
{
    int str1_len = (n1 > my_strlen(str1) ? my_strlen(str1) : n1);
    int str2_len = (n2 > my_strlen(str2) ? my_strlen(str2) : n2);
    char *result = malloc(sizeof(char) * (str1_len + str2_len + 1));

    if (!result)
        return NULL;
    my_strncpy(result, str1, n1);
    my_strncat(result, str2, n2);
    return result;
}

char *my_special_strcat(char *str1, int n1, char *str2, int n2)
{
    if (!str1 || !str2)
        return NULL;
    if (n1 == 0 && n2 == 0) {
        return NULL;
    }
    if (n1 == 0) {
        return my_strdup(str2);
    } else if (n2 == 0) {
        return my_strdup(str1);
    }
    return concatenate(str1, n1, str2, n2);
}
