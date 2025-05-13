/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** get_parameter_value
*/

#include "project.h"

int get_parameter_value(resources_t *resources, int pos, int size)
{
    int value = 0;

    for (int i = 0; i < size; i++) {
        value = (value << 8) | (unsigned char)resources->arena[pos + i]
            % MEM_SIZE;
    }
    return value;
}
