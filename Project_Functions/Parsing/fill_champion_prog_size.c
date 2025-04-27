/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** fill_champion_prog_size
*/

#include "project.h"

int fill_champion_prog_size(FILE *file, champion_t *champion)
{
    if (fread(&(champion->prog_size), sizeof(int), 1, file) != 1) {
        fclose(file);
        return -1;
    }
    champion->prog_size =
        convert_big_endian_to_little_endian(champion->prog_size);
    return 0;
}
