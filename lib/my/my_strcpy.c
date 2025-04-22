/*
** EPITECH PROJECT, 2024
** mmy_print_comb
** File description:
** day 3, task05
** my_print_comb.c
*/
#include "../../include/corewar.h"

char *my_strcpy(char *dest, char const *src)
{
    int size = my_strlen(src);

    dest = malloc(sizeof(char) * size + 1);
    for (int i = 0; i < size; i++) {
        dest[i] = src[i];
    }
    dest[size] = '\0';
    return dest;
}
