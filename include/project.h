/*
** EPITECH PROJECT, 2024
** project.h
** File description:
** contains project related functions
*/

#include "my.h"
#include "op.h"
#include "define.h"
#include "struct.h"

#ifndef PROJECT
    #define PROJECT

// Basic Project Functions:
int read_file(resources_t *resources, champion_t *champion,
    char *champion_file);

// Run Corewar:
void deploy_champions(resources_t *resources);
void run_corewar(resources_t *resources);

// Initializations:
int initialize_resources(resources_t *resources);
int initialize_champion(champion_t *champion);

// Parsing:
int parse_command_arg(resources_t *resources, int argc, char **argv, int *i);
int check_magic_number(FILE *file, champion_t *champion);
int fill_champion_name(FILE *file, champion_t *champion);
int fill_champion_prog_size(FILE *file, champion_t *champion);
int fill_champion_comment(FILE *file, champion_t *champion);
int fill_champion_code(FILE *file, champion_t *champion);

// Process:
process_t *create_process(void);

// Utility:
uint32_t convert_big_endian_to_little_endian(uint32_t Big_Endian);
int champions_left(resources_t *resources);
void print_arena(resources_t *resources);

// Free Functions:
void free_all(resources_t *resources);

#endif
