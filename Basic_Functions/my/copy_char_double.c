/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-robotfactory-hatim.ouaadi
** File description:
** copy_char
*/

#include "my.h"

char **copy_char_double(char **env)
{
    int i;
    char **new_env;

    for (i = 0; env[i] != NULL; i++);
    new_env = malloc(sizeof(char *) * (i + 2));
    if (!new_env)
        return NULL;
    for (i = 0; env[i] != NULL; i++)
        new_env[i] = my_strdup(env[i]);
    new_env[i] = NULL;
    return new_env;
}
