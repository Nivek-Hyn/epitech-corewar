/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** decode_instruction
*/

#include "project.h"

static int type_mask(int bits)
{
    if (bits == 0b01)
        return T_REG;
    if (bits == 0b10)
        return T_DIR;
    if (bits == 0b11)
        return T_IND;
    return 0;
}

static int read_register(resources_t *resources, process_t *process,
    instr_t *instr, arg_t *arg)
{
    arg->reg = read_mem(resources, process->pc + instr->size, 1);
    instr->size += 1;
    if (arg->reg < 1 || arg->reg > REG_NUMBER)
        return -1;
    arg->value = process->registers[arg->reg - 1];
    return 0;
}

static int read_one_arg(resources_t *resources, process_t *process,
    instr_t *instr, int i)
{
    arg_t *arg = &instr->args[i];
    int dir_size = get_dir_size(instr->op.code);

    if (!(type_mask(arg->type) & instr->op.type[i]))
        return -1;
    if (arg->type == 0b01)
        return read_register(resources, process, instr, arg);
    if (arg->type == 0b10) {
        arg->raw = read_mem(resources, process->pc + instr->size, dir_size);
        arg->value = arg->raw;
        instr->size += dir_size;
        return 0;
    }
    arg->raw = read_mem(resources, process->pc + instr->size, IND_SIZE);
    arg->value = read_mem(resources,
        process->pc + arg->raw % IDX_MOD, REG_SIZE);
    instr->size += IND_SIZE;
    return 0;
}

/*
** Decodes the coding byte and the arguments of the instruction at the
** process pc. Values are signed: a direct or indirect argument written
** as 0xFFFB means -5. An indirect argument is resolved to the 4 bytes
** found at pc + raw % IDX_MOD; long instructions recompute it from raw.
** Returns -1 when an argument type or a register number is invalid.
*/
int decode_instruction(resources_t *resources, process_t *process,
    instr_t *instr)
{
    uint8_t coding_byte = read_mem(resources, process->pc + 1, 1);

    instr->op = instruction_info(process->current_instruction);
    instr->size = 2;
    for (int i = 0; i < instr->op.nbr_args; i++) {
        instr->args[i].type = (coding_byte >> (6 - 2 * i)) & 0b11;
        instr->args[i].reg = 0;
        instr->args[i].raw = 0;
        instr->args[i].value = 0;
        if (read_one_arg(resources, process, instr, i) == -1)
            return -1;
    }
    return 0;
}
