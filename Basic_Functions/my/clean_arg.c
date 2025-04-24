/*
** EPITECH PROJECT, 2025
** B-PSU-200-MAR-2-1-minishell2-hatim.ouaadi
** File description:
** clean_arg
*/

#include "my.h"

void clean_argument(char *arg)
{
    int start = 0;
    int len = my_strlen(arg);
    int i;

    while (arg[start] == ' ' || arg[start] == '\t' || arg[start] == '\n')
        start++;
    if (start > 0) {
        for (i = 0; arg[start + i] != '\0'; i++) {
            arg[i] = arg[start + i];
        }
        arg[i] = '\0';
    }
    len = my_strlen(arg);
    while (len > 0 && (arg[len - 1] == ' '
        || arg[len - 1] == '\n'
        || arg[len - 1] == '\t')) {
        arg[len - 1] = '\0';
        len--;
    }
}
