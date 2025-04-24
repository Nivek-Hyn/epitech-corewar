/*
** EPITECH PROJECT, 2025
** clean_str.c
** File description:
** print word by word a string with only one single space between each words
*/

#include "my.h"

void print_word(char *str, int *i, int debut)
{
    if (debut != 0)
        my_putchar(' ');
    for (; str[*i] != ' ' && str[*i] != '\t' && str[*i] != '\0'; (*i)++) {
        my_putchar(str[*i]);
    }
    (*i)--;
}

void clean_str(char *str)
{
    int i = 0;
    int toggle = 1;
    int debut = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\t') {
            toggle = 1;
        }
        if (str[i] != ' ' && toggle > 0 && str[i] != '\t' && toggle > 0) {
            print_word(str, &i, debut);
            toggle = 0;
            debut = 1;
        }
    }
    my_putchar('\n');
}
