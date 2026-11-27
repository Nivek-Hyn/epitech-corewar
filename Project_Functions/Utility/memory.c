/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** memory
*/

#include "project.h"

int mem_addr(int addr)
{
    addr %= MEM_SIZE;
    if (addr < 0)
        addr += MEM_SIZE;
    return addr;
}

int read_mem(resources_t *resources, int pos, int size)
{
    unsigned int value = get_parameter_value(resources, mem_addr(pos), size);

    if (size == 1)
        return (uint8_t)value;
    if (size == 2)
        return (int16_t)value;
    return (int32_t)value;
}

void write_mem(resources_t *resources, int addr, int value, int owner)
{
    for (int i = 0; i < REG_SIZE; i++) {
        resources->arena[mem_addr(addr + i)] = (value >> (24 - i * 8)) & 0xFF;
        resources->owner[mem_addr(addr + i)] = owner;
        resources->heat[mem_addr(addr + i)] = HEAT_MAX;
    }
}
