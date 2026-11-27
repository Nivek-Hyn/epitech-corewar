/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** initialize_champion
*/

#include "project.h"

int initialize_champion(champion_t *champion)
{
    champion->prog_number = -1;
    champion->load_address = -1;
    champion->name = NULL;
    champion->comment = NULL;
    champion->prog_size = 0;
    champion->code = NULL;
    champion->pulse = 0;
    champion->processes = create_process(NULL);
    if (champion->processes == NULL)
        return -1;
    champion->processes->registers[0] = champion->prog_number;
    champion->processes->pc = champion->load_address;
    return 0;
}
