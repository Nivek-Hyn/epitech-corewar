/*
** EPITECH PROJECT, 2025
** delim_tok.c
** File description:
** parse a string using a delimiter and return the delimiter part
*/

#include "my.h"

static int check_if_delim_token(char *str, char **delim_tokens)
{
    for (int i = 0; delim_tokens[i] != NULL; i++) {
        if (my_strncmp(str, delim_tokens[i], my_strlen(delim_tokens[i])) == 0)
            return i;
    }
    return -1;
}

char *delim_token(char *str, tokenizer_t *tokenizer)
{
    int delim_token_index = -1;

    for (; str[tokenizer->i] != '\0'; (tokenizer->i)++) {
        if (str[tokenizer->i] == '\"') {
            tokenizer->toggle = !tokenizer->toggle;
            continue;
        }
        if (!tokenizer->toggle) {
            delim_token_index = check_if_delim_token(&str[tokenizer->i],
                tokenizer->delim_tokens);
        }
        if (delim_token_index != -1) {
            tokenizer->i += my_strlen(
                tokenizer->delim_tokens[delim_token_index]);
            return my_strdup(tokenizer->delim_tokens[delim_token_index]);
        }
    }
    return NULL;
}

char *delim_tok(char *str, tokenizer_t *tokenizer)
{
    if (!str)
        return NULL;
    if (str[tokenizer->i] == '\0') {
        if (tokenizer->token)
            free(tokenizer->token);
        return NULL;
    }
    if (tokenizer->token)
        free(tokenizer->token);
    return delim_token(str, tokenizer);
}
