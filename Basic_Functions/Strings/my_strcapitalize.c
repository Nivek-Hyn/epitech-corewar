/*
** EPITECH PROJECT, 2024
** my_strcapitalize.c
** File description:
** capitalize words in a string
*/

#include "my.h"

char upper(char c)
{
    if (c >= 'a' && c <= 'z') {
        return c + ('a' - 'A');
    }
    return c;
}

char lower(char c)
{
    if (c >= 'a' && c <= 'z') {
        return c - ('a' - 'A');
    }
    return c;
}

char *my_strcapitalize(char *str)
{
    int i = 0;

    if (is_alpha(str[i]) == 1) {
        upper(str[i]);
    }
    for (i = 1; str[i] != '\0'; i++) {
        if (is_alpha(str[i - 1]) == 0 && is_alpha(str[i]) == 1) {
            upper(str[i]);
        } else {
            lower(str[i]);
        }
    }
    return str;
}
