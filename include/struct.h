/*
** EPITECH PROJECT, 2024
** my_isneg
** File description:
** my_isneg.c
*/

#ifndef STRUCT_H
    #define STRUCT_H

typedef struct instruction_s {
    uint8_t opcode;
    uint8_t coding_byte;
    char **parameters;
    struct instruction_s *next;
} instruction_t;

typedef struct champion_s {
    char *name;
    char *comment;
    int prog_size;
    instruction_t *instructions;
} champion_t;

typedef struct resources_s {
    champion_t **champon_list;
} resources_t;

#endif // STRUCT_H //
