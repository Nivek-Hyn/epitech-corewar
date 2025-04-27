/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** fill_champion_code
*/

#include "project.h"

int fill_champion_code(FILE *file, champion_t *champion)
{
    champion->code = malloc(sizeof(char) * champion->prog_size);
    if (check_malloc(champion->comment,
        "champion->code: Malloc Failed.\n") == -1)
        return -1;
    if (fread(champion->code, sizeof(char),
        champion->prog_size, file) != champion->prog_size) {
        fclose(file);
        return -1;
    }
    return 0;
}
