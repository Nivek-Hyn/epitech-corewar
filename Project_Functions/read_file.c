/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** read_file
*/

#include "project.h"

int check_validity(champion_t *champion, char *champion_file)
{
    if (!champion)
        return -1;
    if (initialize_champion(champion) == -1)
        return -1;
    if (!(my_strstr(champion_file, ".cor")))
        return -1;
}

int read_file(resources_t *resources, champion_t *champion,
    char *champion_file)
{
    FILE *file = NULL;

    if (check_validity(champion, champion_file) == -1)
        return -1;
    champion->prog_number = resources->flags->prog_number;
    champion->load_address = resources->flags->load_address;
    file = fopen(champion_file, "rb");
    if (!file)
        return -1;
    if (check_magic_number(file, champion) == -1 ||
            fill_champion_name(file, champion) == -1 ||
                fill_champion_prog_size(file, champion) == -1 ||
                    fill_champion_comment(file, champion) == -1 ||
                        fill_champion_code(file, champion) == -1)
        return -1;
    fclose(file);
    return 0;
}
