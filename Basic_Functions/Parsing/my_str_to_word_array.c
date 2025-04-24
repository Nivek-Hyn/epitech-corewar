/*
** EPITECH PROJECT, 2025
** my_str_to_word_array.c
** File description:
** transform a char * into a char **
*/

#include "my.h"

char *my_getword(char *str, int *i)
{
    char *word = malloc(sizeof(char) * (my_special_strlen(*i, str, " ") + 1));
    int j = 0;

    if (!word)
        return NULL;
    for (; !is_space(str[*i]) && str[*i] != '\0'; (*i)++) {
        word[j] = str[*i];
        j++;
    }
    word[j] = '\0';
    return word;
}

void str_to_word(char **array, char *str, int i, int *j)
{
    int temp = 1;

    for (; str[*j] != '\0'; (*j)++) {
        if (!is_space(str[*j]) && temp == 1) {
            array[i] = my_getword(str, j);
            temp = 0;
            break;
        }
        if (is_space(str[*j]))
            temp = 1;
    }
}

char **free_str_to_word_array(char **array, int i)
{
    while (i >= 0) {
        if (array[i])
            free(array[i]);
        i--;
    }
    free(array);
    return NULL;
}

char **my_str_to_word_array(char *str)
{
    int size = count_words(str);
    char **array = malloc(sizeof(char *) * (size + 1));
    int i = 0;
    int j = 0;
    int Er = 0;

    if (!array)
        return NULL;
    array[size] = NULL;
    for (i = 0; i < size; i++) {
        array[i] = NULL;
        str_to_word(array, str, i, &j);
        if (!array[i]) {
            Er = 1;
            break;
        }
    }
    if (Er == 1)
        return free_str_to_word_array(array, i);
    return array;
}
