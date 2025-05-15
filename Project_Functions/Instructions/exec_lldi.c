/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** exec_lldi
*/

#include "project.h"

void exec_lldi(resources_t *resources, champion_t *champion,
    process_t *process)
{
    ldi_params_t params;
    int addr;
    unsigned int result;

    if (extract_ldi_params(resources, process, &params) == -1)
        return;
    addr = (process->pc + ((params.value + params.offset))) % MEM_SIZE;
    result = get_parameter_value(resources, addr, 4);
    exec_ldi_write(params.reg, result, process);
}
