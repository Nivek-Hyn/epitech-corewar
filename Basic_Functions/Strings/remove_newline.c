/*
** EPITECH PROJECT, 2024
** remove_newline.c
** File description:
** replace '\n' with '\0'
*/

#include "my.h"

void remove_newline(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n' && str[i + 1] == '\0')
            str[i] = '\0';
    }
}
