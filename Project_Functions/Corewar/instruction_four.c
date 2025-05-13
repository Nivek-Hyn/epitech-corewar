/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** instruction_four
*/

#include "project.h"

void exec_ldi_write(int reg, int value, process_t *process)
{
    if (reg < 1 || reg > REG_NUMBER)
        return;
    process->registers[reg - 1] = value;
    process->carry = (value == 0) ? true : false;
}

int get_value(uint8_t type, int pc_offset,
    process_t *process, resources_t *resources)
{
    int value;
    int reg;

    if (type == 0b01) {
        reg = resources->arena[(process->pc + pc_offset) % MEM_SIZE];
        if (reg < 1 || reg > REG_NUMBER)
            return -1;
        value = process->registers[reg - 1];
        pc_offset += 1;
    } else {
        value = get_parameter_value(resources,
            (process->pc + pc_offset) % MEM_SIZE, 2);
        pc_offset += 2;
    }
    return value;
}

int extract_ldi_params(resources_t *resources,
    process_t *process, ldi_params_t *params)
{
    uint8_t coding_byte = resources->arena[(process->pc + 1) % MEM_SIZE];
    uint8_t type1 = (coding_byte >> 6) & 0b11;
    uint8_t type2 = (coding_byte >> 4) & 0b11;
    uint8_t type3 = (coding_byte >> 2) & 0b11;

    params->pc_offset = 2;
    if (!((type1 == 0b01 || type1 == 0b11)
    && (type2 == 0b01 || type2 == 0b11) && type3 == 0b01))
        return -1;
    params->value = get_value(type1, VALUE_GET);
    if (params->value == -1)
        return -1;
    params->pc_offset += 1;
    params->offset = get_value(type2, VALUE_GET);
    if (params->offset == -1)
        return -1;
    params->pc_offset += 1;
    params->reg = OFS;
    params->pc_offset += 1;
    return 0;
}

void exec_ldi(resources_t *resources, champion_t *champion, process_t *process)
{
    ldi_params_t params;
    int addr;
    int result;

    if (extract_ldi_params(resources, process, &params) == -1)
        return;
    addr = (process->pc + (
        (params.value + params.offset) % IDX_MOD)) % MEM_SIZE;
    result = get_parameter_value(resources, addr, 4);
    exec_ldi_write(params.reg, result, process);
    process->pc = (process->pc + params.pc_offset) % MEM_SIZE;
}

void exec_lfork(resources_t *resources, champion_t *champion,
    process_t *process)
{
    unsigned short index =
        (unsigned short)get_parameter_value(resources,
            (process->pc + 1) % MEM_SIZE, 2);
    process_t *current = champion->processes;

    champion->processes = create_process(champion->processes);
    while (current->next)
        current = current->next;
    current->alive = process->alive;
    current->carry = process->carry;
    current->waiting_cycles = 1;
    current->current_instruction = -1;
    for (int i = 0; i < REG_NUMBER; i++)
        current->registers[i] = process->registers[i];
    current->pc = (current->pc + index) % MEM_SIZE;
}
