/*
** EPITECH PROJECT, 2024
** my_getline.c
** File description:
** stock a line into a char *
*/

#include "my.h"

void my_getline_part_two(char **line, char *str, int i)
{
    int k = 0;

    for (; str[i] != '\n' && str[i] != '\0'; i++) {
        (*line)[k] = str[i];
        k++;
    }
    if (str[i] == '\n') {
        (*line)[k] = '\n';
        (*line)[k + 1] = '\0';
    } else {
        (*line)[k] = '\0';
    }
}

int my_getline(char **line, char *str, int i)
{
    int count = 0;
    int j = i;

    for (; str[j] != '\n' && str[j] != '\0'; j++) {
        count++;
    }
    if (str[j] == '\n')
        count++;
    *line = malloc(sizeof(char) * count + 1);
    if (!*line)
        return -1;
    my_getline_part_two(line, str, i);
    return 0;
}
