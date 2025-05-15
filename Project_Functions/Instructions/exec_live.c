/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** exec_live
*/

#include "project.h"

void exec_live(resources_t *resources, champion_t *champion,
    process_t *process)
{
    process->alive = 1;
    mega_write(1, "The player %d (%s) is alive.\n",
        champion->prog_number, champion->name);
    process->live = true;
    resources->total_lives++;
}
