/*
** EPITECH PROJECT, 2025
** project.c
** File description:
** project
*/

#include "project.h"

int main(int argc, char **argv)
{
    resources_t *resources = malloc(sizeof(resources_t));

    if (!resources)
        return 84;
    free(resources);
    return 0;
}
