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
    bool carry;
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
    uint8_t arena[MEM_SIZE];
    int owner[MEM_SIZE];
} resources_t;

typedef struct sti_param_s {
    unsigned int value2;
    uint8_t type3;
    unsigned int new_pc;
    champion_t *champion;
} sti_param_t;

typedef struct ldi_params_s {
    unsigned int value;
    unsigned int offset;
    unsigned int reg;
    unsigned int pc_offset;
} ldi_params_t;

typedef struct st_params_s {
    uint8_t type2;
    unsigned int reg_final;
    uint32_t value;
    unsigned int offset;
    unsigned int addr_final;
} st_params_t;

#endif // STRUCT_H //
