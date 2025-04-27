/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** fill_champion_comment
*/

#include "project.h"

int fill_champion_comment(FILE *file, champion_t *champion)
{
    champion->comment = malloc(sizeof(char) * COMMENT_LENGTH);
    if (check_malloc(champion->comment,
        "champion->comment: Malloc Failed.\n") == -1)
        return -1;
    if (fread(champion->comment, sizeof(char),
        COMMENT_LENGTH, file) != COMMENT_LENGTH) {
        fclose(file);
        return -1;
    }
    return 0;
}
