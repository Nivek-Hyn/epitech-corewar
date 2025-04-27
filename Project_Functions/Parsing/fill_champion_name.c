/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** fill_champion_name
*/

#include "project.h"

int fill_champion_name(FILE *file, champion_t *champion)
{
    champion->name = malloc(sizeof(char) * PROG_NAME_LENGTH);
    if (check_malloc(champion->name, "champion->name: Malloc Failed.\n") == -1)
        return -1;
    if (fread(champion->name, sizeof(char),
        PROG_NAME_LENGTH, file) != PROG_NAME_LENGTH) {
        fclose(file);
        return -1;
    }
    fseek(file, 4, SEEK_CUR);
    return 0;
}
