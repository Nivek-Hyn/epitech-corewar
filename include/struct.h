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
    char current_instruction;
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
    int owner[MEM_SIZE];
} resources_t;

typedef struct sti_param_s {
    int value2;
    uint8_t type3;
    int new_pc;
    champion_t *champion;
} sti_param_t;

typedef struct ldi_params_s {
    int value;
    int offset;
    int reg;
    int pc_offset;
} ldi_params_t;

typedef struct st_params_s {
    uint8_t type2;
    int reg_final;
    int32_t value;
    int offset;
    int addr_final;
} st_params_t;

#endif // STRUCT_H //
