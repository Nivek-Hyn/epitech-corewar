/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** instructions
*/

#include "project.h"

uint32_t get_bytes_live(int pc, char *arena)
{
    uint32_t bytes = 0;

    for (int i = 0; i < 4; i++)
        bytes = (bytes << 8) | (char)arena[pc + i];
    bytes = convert_big_endian_to_little_endian(bytes);
    return bytes;
}

void exec_live(resources_t *resources, champion_t *champion,
    process_t *process)
{
    uint32_t number = get_bytes_live(process->pc + 1, resources->arena);

    if (number == champion->prog_number) {
        process->alive = 1;
        mega_write(1, "The player %d(%s) is alive.\n", champion->prog_number, champion->name);
    }
}

void exec_ld(resources_t *resources, champion_t *champion,
    process_t *process)
{
    uint8_t coding_byte =
        (uint8_t)resources->arena[(process->pc + 1) % MEM_SIZE];
    uint8_t type1 = (coding_byte >> 6) & 0b11;
    uint8_t type2 = (coding_byte >> 4) & 0b11;

    if ((type1 == 0b10 || type1 == 0b11) && type2 == 0b01) {
        process->carry = 1;
        process->registers[type2] =
            resources->arena[process->pc + type1 % IDX_MOD];
    }
}

void exec_st(resources_t *resources, champion_t *champion,
    process_t *process)
{
    
}

void exec_add(resources_t *resources, champion_t *champion,
    process_t *process)
{
    int first_register_index =
        get_parameter_value(resources, (process->pc + 2) % MEM_SIZE, 1);
    int second_register_index =
        get_parameter_value(resources, (process->pc + 3) % MEM_SIZE, 1);
    int third_register_index =
        get_parameter_value(resources, (process->pc + 4) % MEM_SIZE, 1);

    process->registers[third_register_index - 1] =
        process->registers[first_register_index - 1] +
            process->registers[second_register_index - 1];
}

void exec_sub(resources_t *resources, champion_t *champion,
    process_t *process)
{
    int first_register_index =
        get_parameter_value(resources, (process->pc + 2) % MEM_SIZE, 1);
    int second_register_index =
        get_parameter_value(resources, (process->pc + 3) % MEM_SIZE, 1);
    int third_register_index =
        get_parameter_value(resources, (process->pc + 4) % MEM_SIZE, 1);

    process->registers[third_register_index - 1] =
        process->registers[first_register_index - 1] -
            process->registers[second_register_index - 1];
}

void exec_and(resources_t *resources, champion_t *champion,
    process_t *process)
{
    int first_register_index =
        get_parameter_value(resources, (process->pc + 2) % MEM_SIZE, 1);
    int second_register_index =
        get_parameter_value(resources, (process->pc + 3) % MEM_SIZE, 1);
    int third_register_index =
        get_parameter_value(resources, (process->pc + 4) % MEM_SIZE, 1);

    process->registers[third_register_index - 1] =
        process->registers[first_register_index - 1] &
            process->registers[second_register_index - 1];
}

void exec_or(resources_t *resources, champion_t *champion,
    process_t *process)
{
    int first_register_index =
        get_parameter_value(resources, (process->pc + 2) % MEM_SIZE, 1);
    int second_register_index =
        get_parameter_value(resources, (process->pc + 3) % MEM_SIZE, 1);
    int third_register_index =
        get_parameter_value(resources, (process->pc + 4) % MEM_SIZE, 1);

    process->registers[third_register_index - 1] =
        process->registers[first_register_index - 1] |
            process->registers[second_register_index - 1];
}

void exec_xor(resources_t *resources, champion_t *champion,
    process_t *process)
{
    int first_register_index =
        get_parameter_value(resources, (process->pc + 2) % MEM_SIZE, 1);
    int second_register_index =
        get_parameter_value(resources, (process->pc + 3) % MEM_SIZE, 1);
    int third_register_index =
        get_parameter_value(resources, (process->pc + 4) % MEM_SIZE, 1);

    process->registers[third_register_index - 1] =
        process->registers[first_register_index - 1] ^
            process->registers[second_register_index - 1];
}

void exec_zjmp(resources_t *resources, champion_t *champion,
    process_t *process)
{
    
}

void exec_ldi(resources_t *resources, champion_t *champion,
    process_t *process)
{
    
}

void exec_sti(resources_t *resources, champion_t *champion,
    process_t *process)
{
    
}

void exec_fork(resources_t *resources, champion_t *champion,
    process_t *process)
{
    
}

void exec_lld(resources_t *resources, champion_t *champion,
    process_t *process)
{
    
}

void exec_lldi(resources_t *resources, champion_t *champion,
    process_t *process)
{
    
}

void exec_lfork(resources_t *resources, champion_t *champion,
    process_t *process)
{
    
}

void exec_aff(resources_t *resources, champion_t *champion,
    process_t *process)
{
    
}
