/*
** EPITECH PROJECT, 2024
** my_swap
** File description:
** day 4, task 1
*/
#include "../../include/corewar.h"




void my_swap(void *a, void *b)
{
    void *temp = &a;

    a = &b;
    b = &temp;
}
