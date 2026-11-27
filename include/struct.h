/*
** EPITECH PROJECT, 2024
** my_isneg
** File description:
** my_isneg.c
*/

#include <ncurses.h>

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
    bool live;
    bool forked;
    struct process_s *next;
} process_t;

typedef struct champion_s {
    int prog_number;
    int load_address;
    char *name;
    char *comment;
    int prog_size;
    char *code;
    int pulse;
    process_t *processes;
} champion_t;

typedef struct resources_s {
    champion_t **champion_list;
    int nb_champion;
    flags_t *flags;
    int nbr_cycle;
    int total_lives;
    champion_t *last_live;
    uint8_t arena[MEM_SIZE];
    uint8_t heat[MEM_SIZE];
    int owner[MEM_SIZE];
} resources_t;

typedef struct arg_s {
    uint8_t type;
    int reg;
    int raw;
    int value;
} arg_t;

typedef struct instr_s {
    op_t op;
    arg_t args[MAX_ARGS_NUMBER];
    int size;
} instr_t;

typedef struct color_code_s {
    int color;
    int prog_number;
} color_code_t;

typedef struct graphical_s {
    int cycle;
    int cycle_to_die;
    int cycle_checker;
    champion_t *winner;
    int c;
    int timeout_value;
    int tmp_timeout_value;
    int paused;
    int game_running;
    int offset_y;
    color_code_t **color_code;
    WINDOW *window;
    WINDOW *arena_win;
    WINDOW *info_win;
    WINDOW *params_win;
    WINDOW *help_win;
    int rich_colors;
    int owned_bytes;
    uint8_t cursor[MEM_SIZE];
} graphical_t;

#endif // STRUCT_H //
