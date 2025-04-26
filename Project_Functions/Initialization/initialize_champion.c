/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** initialize_champion
*/

#include "project.h"

void initialize_champion(champion_t *champion)
{
    champion->prog_number = 0;
    champion->load_address = 0;
    champion->name = NULL;
    champion->comment = NULL;
    champion->prog_size = 0;
    champion->code = NULL;
}
