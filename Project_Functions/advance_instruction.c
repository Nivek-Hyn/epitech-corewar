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
    return op_tab[NBR_INSTRUCTIONS - 1];
}

int get_parameter_size(char coding_byte, int bit_index, int second_bit_index)
{
    int first_bit = ((coding_byte & (1 << (8 - bit_index))) ? 1 : 0);
    int second_bit = ((coding_byte & (1 << (8 - second_bit_index))) ? 1 : 0);

    if (first_bit == 0 && second_bit == 1)
        return 1;
    if (first_bit == 1 && second_bit == 0)
        return DIR_SIZE;
    if (first_bit == 1 && second_bit == 1)
        return IND_SIZE;
    return 0;
}

void advance_instruction(resources_t *resources, process_t *process)
{
    int nbr_params = instruction_info(process->current_instruction).nbr_args;
    int has_coding_byte =
        check_if_has_coding_byte(process->current_instruction);
    int advance = 1;

    if (has_coding_byte != 1) {
        advance += DIR_SIZE;
    } else {
        advance++;
        for (int i = 1; i < nbr_params * 2; i += 2) {
            advance += get_parameter_size(
                resources->arena[process->pc] + 1, i, i + 1);
        }
    }
    process->pc += advance;
}
