/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** initialize_champion
*/

#include "project.h"

process_t *create_process(void)
{
    process_t *new_process = malloc(sizeof(process_t));

    if (check_malloc(new_process, "new_process: Malloc Failed.\n") == -1)
        return NULL;
    new_process->alive = 1;
    for (int i = 0; i < REG_NUMBER; i++)
        new_process->registers[i] = 0;
    new_process->carry = 0;
    new_process->pc = 0;
    new_process->next = NULL;
    return new_process;
}

int initialize_champion(champion_t *champion)
{
    champion->prog_number = 0;
    champion->load_address = 0;
    champion->name = NULL;
    champion->comment = NULL;
    champion->prog_size = 0;
    champion->code = NULL;
    champion->processes = create_process();
    if (champion->processes == NULL)
        return -1;
    champion->processes->registers[0] = champion->prog_number;
    champion->processes->pc = champion->load_address;
    return 0;
}
