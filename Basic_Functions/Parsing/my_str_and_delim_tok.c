/*
** EPITECH PROJECT, 2025
** my_strtok.c
** File description:
** parse a string using a delimiter and return the string part
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

static int is_delimiter(char *str, char *delim, int *i, char **delim_tokens)
{
    if (contain_char(delim, str[*i]) == 1)
        return 1;
    if (check_if_delim_token(&str[*i], delim_tokens) != -1) {
        return 1;
    }
    return 0;
}

static int my_strtok_check_quote(char *str, char *delim, int *i,
    int *toggle)
{
    if (contain_char(delim, '\"') != 1) {
        if (*toggle == 0 && str[*i] == '\"') {
            *toggle = 1;
            return 1;
        }
        if (*toggle == 1 && str[*i] == '\"') {
            *toggle = 0;
            return 1;
        }
    }
    return 0;
}

static char *fill_token(char *str, int count, tokenizer_t *tokenizer)
{
    char *token = malloc(sizeof(char) * (count + 1));
    int toggle = 0;

    if (!token)
        return NULL;
    token[count] = '\0';
    for (int j = 0; (toggle == 0 && is_delimiter(
        str, tokenizer->delim, &tokenizer->i, tokenizer->delim_tokens) != 1
        && str[tokenizer->i] != '\0') ||
        (toggle == 1 && str[tokenizer->i] != '\0'); (tokenizer->i)++) {
        if (my_strtok_check_quote(
            str, tokenizer->delim, &tokenizer->i, &toggle) != 1) {
            token[j] = str[tokenizer->i];
            j++;
        }
    }
    if (contain_char(tokenizer->delim, str[tokenizer->i]) == 1)
        (tokenizer->i)++;
    return token;
}

static int count_token(char *str, tokenizer_t *tokenizer)
{
    int count = 0;
    int toggle = 0;

    for (int j = tokenizer->i; (toggle == 0 &&
        is_delimiter(str, tokenizer->delim, &j, tokenizer->delim_tokens) != 1
        && str[j] != '\0') ||
        (toggle == 1 && str[j] != '\0'); j++) {
        if (my_strtok_check_quote(str, tokenizer->delim, &j, &toggle) != 1)
            count++;
    }
    return count;
}

char *my_str_and_delim_tok_two(char *str, tokenizer_t *tokenizer)
{
    int count = 0;

    if (str[tokenizer->i] == '\0') {
        if (tokenizer->token)
            free(tokenizer->token);
        return NULL;
    }
    count = count_token(str, tokenizer);
    if (tokenizer->token)
        free(tokenizer->token);
    return fill_token(str, count, tokenizer);
}

char *my_str_and_delim_tok(char *str, tokenizer_t *tokenizer)
{
    int delim_token_index = -1;

    if (!str)
        return NULL;
    while (contain_char(tokenizer->delim, str[tokenizer->i]) == 1)
        (tokenizer->i)++;
    delim_token_index = check_if_delim_token(&str[tokenizer->i],
        tokenizer->delim_tokens);
    if (delim_token_index != -1) {
        if (tokenizer->token)
            free(tokenizer->token);
        tokenizer->i += my_strlen(tokenizer->delim_tokens[delim_token_index]);
        return my_strdup(tokenizer->delim_tokens[delim_token_index]);
    }
    return my_str_and_delim_tok_two(str, tokenizer);
}
