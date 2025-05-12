/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** instruction_second
*/

#include "project.h"

void exec_st(resources_t *resources, champion_t *champion,
    process_t *process)
{
    uint8_t coding_byte = resources->arena[(process->pc + 1) % MEM_SIZE];
    st_params_t p;
    uint8_t type1 = (coding_byte >> 6) & 0b11;
    int reg = 0;

    p.type2 = (coding_byte >> 4) & 0b11;
    p.value = 0;
    p.offset = 0;
    if (!(type1 == 0b01 && (p.type2 == 0b01 || p.type2 == 0b11)))
        return;
    reg = resources->arena[(process->pc + 2) % MEM_SIZE];
    if (reg < 1 || reg > REG_NUMBER)
        return;
    p.value = process->registers[reg - 1];
    st_checking(resources, process, champion, &p);
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

    if (first_register_index < 1 || first_register_index > REG_NUMBER ||
        second_register_index < 1 || second_register_index > REG_NUMBER ||
        third_register_index < 1 || third_register_index > REG_NUMBER)
        return;
    process->registers[third_register_index - 1] =
        process->registers[first_register_index - 1] +
            process->registers[second_register_index - 1];
    process->carry =
        (process->registers[third_register_index - 1] == 0) ? 1 : 0;
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

    if (first_register_index < 1 || first_register_index > REG_NUMBER ||
        second_register_index < 1 || second_register_index > REG_NUMBER ||
        third_register_index < 1 || third_register_index > REG_NUMBER)
        return;
    process->registers[third_register_index - 1] =
        process->registers[first_register_index - 1] -
            process->registers[second_register_index - 1];
    process->carry =
        (process->registers[third_register_index - 1] == 0) ? 1 : 0;
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

    if (first_register_index < 1 || first_register_index > REG_NUMBER ||
        second_register_index < 1 || second_register_index > REG_NUMBER ||
        third_register_index < 1 || third_register_index > REG_NUMBER)
        return;
    process->registers[third_register_index - 1] =
        process->registers[first_register_index - 1] &
            process->registers[second_register_index - 1];
    process->carry =
        (process->registers[third_register_index - 1] == 0) ? 1 : 0;
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

    if (first_register_index < 1 || first_register_index > REG_NUMBER ||
        second_register_index < 1 || second_register_index > REG_NUMBER ||
        third_register_index < 1 || third_register_index > REG_NUMBER)
        return;
    process->registers[third_register_index - 1] =
        process->registers[first_register_index - 1] |
            process->registers[second_register_index - 1];
    process->carry =
        (process->registers[third_register_index - 1] == 0) ? 1 : 0;
}
