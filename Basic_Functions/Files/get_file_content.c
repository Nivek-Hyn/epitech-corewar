/*
** EPITECH PROJECT, 2025
** get_file_content.c
** File description:
** return the file content
*/

#include "my.h"

char *get_file_content(char *file_path)
{
    int fd = fs_open_file(file_path);
    int size = file_size(file_path);
    char *content = malloc(sizeof(char) * (size + 1));

    if (!content)
        return NULL;
    read(fd, content, size);
    close(fd);
    if (!content) {
        return NULL;
    }
    content[size] = '\0';
    return content;
}
