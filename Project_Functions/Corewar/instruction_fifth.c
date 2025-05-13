/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** instruction_fifth
*/

#include "project.h"

void exec_lldi(resources_t *resources, champion_t *champion,
    process_t *process)
{
    ldi_params_t params;
    int addr;
    int result;

    if (extract_ldi_params(resources, process, &params) == -1)
        return;
    addr = (process->pc + ((params.value + params.offset))) % MEM_SIZE;
    result = get_parameter_value(resources, addr, 4);
    exec_ldi_write(params.reg, result, process);
    process->pc = (process->pc + params.pc_offset) % MEM_SIZE;
}

void exec_aff(resources_t *resources, champion_t *champion,
    process_t *process)
{
    uint8_t coding_byte = resources->arena[(process->pc + 1) % MEM_SIZE];
    uint8_t type1 = (coding_byte >> 6) & 0b11;
    int value;
    int reg;

    if (type1 != 0b01) {
        return;
    }
    reg = resources->arena[(process->pc + 2) % MEM_SIZE];
    if (reg < 1 || reg > REG_NUMBER)
        return;
    value = process->registers[reg - 1];
    mega_write(1, "%c", value % 256);
    process->pc = (process->pc + 3) % MEM_SIZE;
}
