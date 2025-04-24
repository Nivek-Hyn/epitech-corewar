/*
** EPITECH PROJECT, 2025
** execute_command.c
** File description:
** execute a command
*/

#include "my.h"

int execute_command(char *command, char **args, char **env)
{
    if (execve(command, args, env) == -1) {
        perror("execve");
        return 84;
    }
    return 0;
}
