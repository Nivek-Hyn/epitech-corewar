/*
** EPITECH PROJECT, 2024
** my_strcat_malloc.c
** File description:
** malloc to concatenate 2 string
*/

#include "my.h"

int check_error(char *dest, char *src, char *result)
{
    if (!result)
        return -1;
    if (!dest && !src) {
        free(result);
        return -1;
    }
    if (!src) {
        result = my_strcpy(result, dest);
        return 1;
    }
    if (!dest) {
        result = my_strcpy(result, src);
        return 1;
    }
    return 0;
}

char *my_strcat_malloc(char *dest, char *src)
{
    int destlen = (dest != NULL) ? my_strlen(dest) : 0;
    int srclen = (src != NULL) ? my_strlen(src) : 0;
    char *result = malloc(sizeof(char) * (destlen + srclen + 1));
    int Er = check_error(dest, src, result) == -1;

    if (Er == -1) {
        return NULL;
    } else if (Er == 1) {
        return result;
    }
    my_strcpy(result, dest);
    for (int i = 0; i < srclen; i++) {
        result[destlen + i] = src[i];
    }
    result[destlen + srclen] = '\0';
    return result;
}
