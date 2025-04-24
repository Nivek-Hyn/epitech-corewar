/*
** EPITECH PROJECT, 2024
** my_strcmp
** File description:
** Day 6, task 6
*/

#include "../../include/corewar.h"

char *nb_to_str(int i)
{
    char *str = malloc(sizeof(char) * nb_len(i));
    int a = 0;

    if (i == 0){
        str[a] = '0';
        a++;
    }
    while (i > 0){
        str[a] = i % 10 + '0';
        i = i / 10;
        a++;
    }
    str[a] = '\0';
    return my_revstr(str);
}

char *my_strcat(char *dest, char *str)
{
    char *added = malloc(sizeof(char) *
        (my_strlen(dest) + my_strlen(str)) + 1);
    int i = 0;
    int a = 0;

    while (dest[i] != '\0'){
        added[i] = dest[i];
        i++;
    }
    while (str[a] != '\0'){
        added[i + a] = str[a];
        a++;
    }
    added[i + a] = '\0';
    return added;
}
