/*
** EPITECH PROJECT, 2024
** file_size.c
** File description:
** return file size
*/

#include "my.h"

int file_size(char *filepath)
{
    struct stat file_info;

    if (stat(filepath, &file_info) == -1) {
        write(2, "stat: Bad address\n", 18);
        return 0;
    }
    return file_info.st_size;
}
