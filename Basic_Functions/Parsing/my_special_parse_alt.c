/*
** EPITECH PROJECT, 2025
** my_special_parse_alt.c
** File description:
** return an array after parsing using strtok
*/

#include "my.h"

static void fill_array(char *str, tokenizer_t *tokenizer, char **array)
{
    int i = 0;

    if (tokenizer->token)
        free(tokenizer->token);
    tokenizer->token = NULL;
    tokenizer->i = 0;
    tokenizer->token = my_str_and_delim_tok(str, tokenizer);
    while (tokenizer->token) {
        array[i] = my_strdup(tokenizer->token);
        i++;
        tokenizer->token = my_str_and_delim_tok(str, tokenizer);
    }
}

char **my_special_parse_alt(char *str, tokenizer_t *tokenizer)
{
    char **array = NULL;
    int i = 0;

    tokenizer->i = 0;
    if (!str)
        return NULL;
    tokenizer->token = my_str_and_delim_tok(str, tokenizer);
    while (tokenizer->token) {
        i++;
        tokenizer->token = my_str_and_delim_tok(str, tokenizer);
    }
    array = malloc(sizeof(char *) * (i + 1));
    if (!array)
        return NULL;
    array[i] = NULL;
    fill_array(str, tokenizer, array);
    return array;
}
