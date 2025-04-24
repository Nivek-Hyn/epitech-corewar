/*
** EPITECH PROJECT, 2024
** my_sort_int_array.c
** File description:
** sort an array of int
*/

#include "my.h"

void swap_nbr(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}

void superior(int *a, int *b)
{
    if (*a > *b) {
        swap_nbr(&*a, &*b);
    }
}

void my_sort_int_array(int *array, int size)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - 1 - i; j++) {
            superior(&array[j], &array[j + 1]);
        }
    }
}
