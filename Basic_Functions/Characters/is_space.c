/*
** EPITECH PROJECT, 2025
** is_space.c
** File description:
** condition if the character is a space, tab or newline
*/

#include "my.h"

int is_space(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}
