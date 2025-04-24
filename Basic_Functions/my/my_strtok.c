/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-robotfactory-julien.leiner
** File description:
** my_strtok
*/

#include "../include/corewar.h"


char *my_strtok(char *str, const char *delim)
{
    static char *last;
    char *start;

    if (str != NULL)
        last = str;
    if (last == NULL)
        return NULL;
    while (*last && my_strchr(delim, *last))
        last++;
    if (*last == '\0')
        return NULL;
    start = last;
    while (*last && !my_strchr(delim, *last))
        last++;
    if (*last) {
        *last = '\0';
        last++;
    }
    return start;
}
