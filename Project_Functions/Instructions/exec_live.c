/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** exec_live
*/

#include "project.h"

/*
** Marks the process as alive and credits the player whose number is the
** argument of live, which is how the last player reported alive wins.
*/
champion_t *report_live(resources_t *resources, process_t *process)
{
    int number = read_mem(resources, process->pc + 1, DIR_SIZE);

    process->alive = 1;
    process->live = true;
    resources->total_lives++;
    for (int i = 0; resources->champion_list[i] != NULL; i++) {
        if (resources->champion_list[i]->prog_number == number) {
            resources->last_live = resources->champion_list[i];
            return resources->champion_list[i];
        }
    }
    return NULL;
}

void exec_live(resources_t *resources, champion_t *champion,
    process_t *process)
{
    champion_t *target = report_live(resources, process);

    if (target == NULL)
        return;
    mega_write(1, "The player %d(%s) is alive.\n",
        target->prog_number, target->name);
}
