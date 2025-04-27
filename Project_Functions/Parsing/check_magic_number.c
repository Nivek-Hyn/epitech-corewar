/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** check_magic_number
*/

#include "project.h"

int check_magic_number(FILE *file, champion_t *champion)
{
    int magic_number = 0;

    if (fread(&magic_number, sizeof(int), 1, file) != 1) {
        fclose(file);
        return -1;
    }
    magic_number = convert_big_endian_to_little_endian(magic_number);
    if (magic_number != COREWAR_EXEC_MAGIC)
        return -1;
    return 0;
}
