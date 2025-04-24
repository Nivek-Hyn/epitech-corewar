/*
** EPITECH PROJECT, 2024
** my_special_strlen.c
** File description:
** return number of character (choose a starting index and a delimiter)
*/

#include "my.h"

int my_special_strlen(int i, char *str, char *delimiter)
{
    int count = 0;

    for (; contain_char(delimiter, str[i]) != 1 && str[i] != '\0'; i++) {
        count++;
    }
    return count;
}
