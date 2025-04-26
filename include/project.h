/*
** EPITECH PROJECT, 2024
** project.h
** File description:
** contains project related functions
*/

#include "my.h"

#ifndef PROJECT
    #define PROJECT

// Basic Project Functions:
int read_file(resources_t *resources, champion_t *champion,
    char *champion_file);

// Initializations:
int initialize_resources(resources_t *resources);
void initialize_champion(champion_t *champion);

// Parsing:
int parse_command_arg(resources_t *resources, int argc, char **argv, int *i);

// Free Functions:
void free_all(resources_t *resources);

#endif
