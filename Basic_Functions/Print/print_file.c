/*
** EPITECH PROJECT, 2025
** print_file.c
** File description:
** prints the file's content.
*/

#include "my.h"

void print_file(char *file_path)
{
    int fd = fs_open_file(file_path);
    int size = file_size(file_path);
    char *text = malloc(sizeof(char) * (size + 1));

    if (!text)
        return;
    read(fd, text, size);
    text[size] = '\0';
    mega_write(STDOUT_FILENO, "%s", text);
    free(text);
    close(fd);
}
