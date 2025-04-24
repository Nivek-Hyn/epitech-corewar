/*
** EPITECH PROJECT, 2025
** count_words.c
** File description:
** return number of words in a string
*/

#include "my.h"

int count_words(char *str)
{
    int count = 0;
    int temp = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_space(str[i]) && temp == 1) {
            count++;
            temp = 0;
        }
        if (is_space(str[i]))
            temp = 1;
    }
    return count;
}
