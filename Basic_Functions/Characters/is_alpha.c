/*
** EPITECH PROJECT, 2025
** alpha.c
** File description:
** check if it's an alphanumerical character
*/

#include "my.h"

int is_alpha(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return 1;
    }
    return 0;
}
