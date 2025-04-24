/*
** EPITECH PROJECT, 2024
** my_strncomp.c
** File description:
** compare 2 strings starting from n index
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (i < n && s1[i] && s2[i]) {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
        i++;
    }
    if (i < n)
        return s1[i] - s2[i];
    return 0;
}
