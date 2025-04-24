/*
** EPITECH PROJECT, 2025
** my_write.c
** File description:
** write the whole string at once
*/

#include "my.h"

void my_write(int fd, char *str)
{
    if (!str)
        return;
    write(fd, str, my_strlen(str));
}
