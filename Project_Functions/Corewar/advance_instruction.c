/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** advance_instruction
*/

#include "project.h"

int check_if_has_coding_byte(char opcode)
{
    switch (opcode) {
        case 1:
            return 0;
        case 9:
            return 0;
        case 12:
            return 0;
        case 15:
            return 0;
        default:
            return 1;
    }
}

const op_t instruction_info(char opcode)
{
    for (int i = 0; op_tab[i].code != 0; i++) {
        if (op_tab[i].code == opcode)
            return op_tab[i];
    }
    return op_tab[NBR_INSTRUCTIONS];
}

int get_dir_size(char opcode)
{
    if (opcode == 9 || opcode == 10 || opcode == 11 ||
        opcode == 12 || opcode == 14 || opcode == 15)
        return DIR_SIZE / 2;
    return DIR_SIZE;
}

int get_parameter_size(uint8_t coding_byte, int param_index, char opcode)
{
    int bits = (coding_byte >> (6 - 2 * param_index)) & 0b11;

    if (bits == 0b01)
        return 1;
    if (bits == 0b10)
        return get_dir_size(opcode);
    if (bits == 0b11)
        return 2;
    return 0;
}

void advance_instruction(resources_t *resources, process_t *process)
{
    const op_t op = instruction_info(process->current_instruction);
    int has_coding_byte =
        check_if_has_coding_byte(process->current_instruction);
    int advance = 1;

    if (has_coding_byte != 1) {
        advance += get_dir_size(process->current_instruction);
    } else {
        advance++;
        for (int i = 0; i < op.nbr_args; i++) {
            advance += get_parameter_size(resources->arena[(process->pc + 1)
                % MEM_SIZE], i, process->current_instruction);
        }
    }
    process->pc = (process->pc + advance) % MEM_SIZE;
}
