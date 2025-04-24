/*
** EPITECH PROJECT, 2025
** initialize_tokenizer.c
** File description:
** initialize the tokenizer struct
*/

#include "my.h"

tokenizer_t *initialize_tokenizer(char *delim, char **delim_tokens)
{
    tokenizer_t *tokenizer = malloc(sizeof(tokenizer_t));

    if (!tokenizer)
        return NULL;
    tokenizer->delim = my_strdup(delim);
    tokenizer->token = NULL;
    tokenizer->i = 0;
    tokenizer->toggle = 0;
    tokenizer->delim_tokens = array_dup(delim_tokens);
    return tokenizer;
}
