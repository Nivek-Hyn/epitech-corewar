/*
** EPITECH PROJECT, 2025
** my_parse.c
** File description:
** parses multiple parts using a delimiter, returns an array
*/

#include "my.h"

int my_parse_count_words(char *str, char *delimiter)
{
    int size = 0;
    int temp = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (contain_char(delimiter, str[i]) != 1 && temp == 1) {
            size++;
            temp = 0;
        }
        if (contain_char(delimiter, str[i]) == 1)
            temp = 1;
    }
    return size;
}

char *my_parse_word(char *str, int *i, char *delimiter)
{
    char *word = malloc(sizeof(char) *
        (my_special_strlen(*i, str, delimiter) + 1));
    int j = 0;

    if (!word)
        return NULL;
    for (; contain_char(delimiter, str[*i]) != 1 && str[*i] != '\0'; (*i)++) {
        word[j] = str[*i];
        j++;
    }
    word[j] = '\0';
    return word;
}

void my_parse_str_to_word(char **array, char *str, int i[2], char *delimiter)
{
    int temp = 1;

    for (; str[i[1]] != '\0'; i[1]++) {
        if (contain_char(delimiter, str[i[1]]) != 1 && temp == 1) {
            array[i[0]] = my_parse_word(str, &i[1], delimiter);
            temp = 0;
            break;
        }
        if (contain_char(delimiter, str[i[1]]) == 1)
            temp = 1;
    }
}

char **free_my_parse_array(char **array, int i)
{
    while (i >= 0) {
        if (array[i])
            free(array[i]);
        i--;
    }
    free(array);
    return NULL;
}

char **my_parse(char *str, char *delimiter)
{
    int size = my_parse_count_words(str, delimiter);
    char **array = malloc(sizeof(char *) * (size + 1));
    int i[2] = {0, 0};
    int Er = 0;

    if (!array)
        return NULL;
    array[size] = NULL;
    for (i[0] = 0; i[0] < size; i[0]++) {
        array[i[0]] = NULL;
        my_parse_str_to_word(array, str, i, delimiter);
        if (!array[i[0]]) {
            Er = 1;
            break;
        }
    }
    if (Er == 1)
        return free_my_parse_array(array, i[0]);
    return array;
}
