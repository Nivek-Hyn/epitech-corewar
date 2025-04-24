/*
** EPITECH PROJECT, 2024
** my_swap.c
** File description:
** swap 2 characters or numbers
*/

#include "my.h"

void my_swap(int *a, int *b)
{
    int c = *a;

    *a = *b;
    *b = c;
}
