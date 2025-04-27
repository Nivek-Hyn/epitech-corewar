/*
** EPITECH PROJECT, 2024
** my_isneg
** File description:
** my_isneg.c
*/

#ifndef STRUCT_H
    #define STRUCT_H

typedef struct flags {
    int dump;
    int n;
    int prog_number;
    int a;
    int load_address;
} flags_t;

typedef struct process_s {
    int alive;
    int registers[REG_NUMBER];
    int carry;
    int pc;
    int waiting_cycles;
    struct process_s *next;
} process_t;

typedef struct champion_s {
    int prog_number;
    int load_address;
    char *name;
    char *comment;
    int prog_size;
    char *code;
    process_t *processes;
} champion_t;

typedef struct resources_s {
    champion_t **champion_list;
    int nb_champion;
    flags_t *flags;
    int nbr_cycle;
    char arena[MEM_SIZE];
} resources_t;

#endif // STRUCT_H //
