/*
** EPITECH PROJECT, 2024
** fs_open_file.c
** File description:
** open a file, return fd
*/

#include "my.h"

int fs_open_file(char const *filepath)
{
    int fd;

    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        write(2, "open: Bad address\n", 18);
        return fd;
    } else {
        return fd;
    }
}
