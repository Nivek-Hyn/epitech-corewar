/*
** EPITECH PROJECT, 2025
** free_tokenizer.c
** File description:
** free the tokenizer struct
*/

#include "my.h"

void free_tokenizer(tokenizer_t *tokenizer)
{
    if (tokenizer->delim)
        free(tokenizer->delim);
    if (tokenizer->token)
        free(tokenizer->token);
    free_array(tokenizer->delim_tokens);
    free(tokenizer);
}
