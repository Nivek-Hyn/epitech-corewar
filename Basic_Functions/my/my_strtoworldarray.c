/*
** EPITECH PROJECT, 2024
** my_is_prime
** File description:
** Day 5, task 6
*/
#include "my.h"

int nb_lign(char *str)
{
    int r = 1;

    for (int i = 0; str[i] != 0; i++) {
        if (str[i] == '\n')
            r++;
    }
    return r;
}

int nb_char(char *str)
{
    int i = 0;
    int j = 0;

    while (str[j] != '\n' && str[j] != '\0')
        j++;
    i = j + 1;
    while (str[i] != '\n' && str[i] != '\0')
        i++;
    i = i - (j + 1);
    return i;
}

int nb_mot(char *str)
{
    int i = 0;
    int nb = 0;

    while (str[i] != '\0'){
        if (str[i] == ' ')
            nb++;
        i++;
    }
    return nb;
}

char **str_to_array(char *buff)
{
    int b = 0;
    int j = 0;
    int n = nb_lign(buff);
    char **arr = malloc((n + 1) * sizeof(char *));
    int z = 0;

    for (int k = 0; k != n; k++)
        arr[k] = malloc(sizeof(char) * (strlen_lign(buff) + 1));
    for (int i = 0; buff[i] != '\0'; i++){
        if (buff[i] != '\n'){
            arr[j][b] = buff[i];
            b++;
        } else {
            arr[j][b] = '\0';
            j++;
            b = 0;
        }
    }
    arr[j][b] = '\0';
    return arr;
}
