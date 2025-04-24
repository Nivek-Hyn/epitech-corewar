/*
** EPITECH PROJECT, 2025
** special_count_words.c
** File description:
** return number of words in a string, words are separated by a delimiter
*/

#include "my.h"

int special_count_words(char *str, char delimiter)
{
    int count = 0;
    int temp = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != delimiter && temp == 1) {
            count++;
            temp = 0;
        }
        if (str[i] == delimiter)
            temp = 1;
    }
    return count;
}
