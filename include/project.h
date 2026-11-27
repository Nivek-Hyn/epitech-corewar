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
void check_processes_live(resources_t *resources, champion_t *champion);
void check_champions_processes_live(resources_t *resources);
void cycles_and_lives_manager(resources_t *resources,
    int *cycle_to_die, int *cycle_checker);
void run_instruction(resources_t *resources, champion_t *champion,
    process_t *process);
void advance_instruction(resources_t *resources, process_t *process);
champion_t *find_winning_champion(resources_t *resources);

// Initializations:
int initialize_resources(resources_t *resources);
int initialize_champion(champion_t *champion);
void set_champions_prog_number(resources_t *resources);

// Parsing:
int parse_command_arg(resources_t *resources, int argc, char **argv, int *i);
int check_magic_number(FILE *file, champion_t *champion);
int fill_champion_name(FILE *file, champion_t *champion);
int fill_champion_prog_size(FILE *file, champion_t *champion);
int fill_champion_comment(FILE *file, champion_t *champion);
int fill_champion_code(FILE *file, champion_t *champion);

// Process:
process_t *create_process(process_t *processes);
void run_all_processes(resources_t *resources);

// Exec instruction:
void exec_live(resources_t *resources, champion_t *champion,
    process_t *process);
void exec_ld(resources_t *resources, champion_t *champion,
    process_t *process);
void exec_st(resources_t *resources, champion_t *champion,
    process_t *process);
void exec_add(resources_t *resources, champion_t *champion,
    process_t *process);
void exec_sub(resources_t *resources, champion_t *champion,
    process_t *process);
void exec_and(resources_t *resources, champion_t *champion,
    process_t *process);
void exec_or(resources_t *resources, champion_t *champion,
    process_t *process);
void exec_xor(resources_t *resources, champion_t *champion,
    process_t *process);
void exec_zjmp(resources_t *resources, champion_t *champion,
    process_t *process);
void exec_ldi(resources_t *resources, champion_t *champion,
    process_t *process);
void exec_sti(resources_t *resources, champion_t *champion,
    process_t *process);
void exec_fork(resources_t *resources, champion_t *champion,
    process_t *process);
void exec_lld(resources_t *resources, champion_t *champion,
    process_t *process);
void exec_lldi(resources_t *resources, champion_t *champion,
    process_t *process);
void exec_lfork(resources_t *resources, champion_t *champion,
    process_t *process);
void exec_aff(resources_t *resources, champion_t *champion,
    process_t *process);

// Utility:
uint32_t convert_big_endian_to_little_endian(uint32_t Big_Endian);
int champions_left(resources_t *resources);
void print_arena(resources_t *resources);
unsigned int get_parameter_value(resources_t *resources, int pos, int size);
int mem_addr(int addr);
int read_mem(resources_t *resources, int pos, int size);
void write_mem(resources_t *resources, int addr, int value, int owner);
int decode_instruction(resources_t *resources, process_t *process,
    instr_t *instr);
int get_dir_size(char opcode);
champion_t *report_live(resources_t *resources, process_t *process);
const op_t instruction_info(char opcode);
int get_color_code(int index);

// Free Functions:
void free_all(resources_t *resources);

// Bonus:
void run_graphical_corewar(resources_t *resources);
void run_all_processes_graphical(resources_t *resources);
void run_instruction_graphical(resources_t *resources, champion_t *champion,
    process_t *process);
void corewar_system(resources_t *resources, graphical_t *graphical);
void initialize_windows(graphical_t *graphical);
void initialize_ncurses(void);
void initialize_graphical(graphical_t *graphical);
void free_all_graphical(graphical_t *graphical);
void key_input_manager(resources_t *resources, graphical_t *graphical);
void print_stats(resources_t *resources, graphical_t *graphical);
void show_menu(graphical_t *graphical);
void print_arena_ncurses(resources_t *resources, graphical_t *graphical);
void initialize_color_code(resources_t *resources, graphical_t *graphical);
void set_color(graphical_t *graphical, int owner, int *color_pair);
void print_info_graphical(graphical_t *graphical, resources_t *resources);
void print_params_graphical(graphical_t *graphical, resources_t *resources);
void print_help_graphical(graphical_t *graphical);
void initialize_rich_colors(graphical_t *graphical);
void update_visual_effects(resources_t *resources, graphical_t *graphical);
int cell_attributes(resources_t *resources, graphical_t *graphical, int i);
int champion_index(resources_t *resources, int prog_number);
int count_processes(champion_t *champion);
int count_territory(resources_t *resources, int prog_number);
int count_owned(resources_t *resources);
void print_winner_banner(resources_t *resources, graphical_t *graphical);
void print_champion_stats(graphical_t *graphical, resources_t *resources,
    int champion_index, int y);

#endif
