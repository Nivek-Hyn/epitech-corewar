/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** deploy_champions
*/

#include "project.h"

void set_spawn_to_load_address(resources_t *resources, champion_t *champion)
{
    int arena_pos = 0;

    printf("toi at: %d\n", champion->load_address);
    for (int i = 0; i < champion->prog_size; i++) {
        arena_pos = (champion->load_address + i) % MEM_SIZE;
        resources->arena[arena_pos] = champion->code[i];
    }
}

int calculate_distance(int pos1, int pos2)
{
    int distance = 0;

    pos1 = (pos1 + MEM_SIZE) % MEM_SIZE;
    pos2 = (pos2 + MEM_SIZE) % MEM_SIZE;
    if (pos1 > pos2) {
        distance = pos1 - pos2;
    } else {
        distance = pos2 - pos1;
    }
    if (distance > MEM_SIZE / 2) {
        distance = MEM_SIZE - distance;
    }
    return distance;
}

void find_farthest_point(resources_t *resources,
    champion_t *champion, int *best_position, int pos)
{
    int tmp = 0;
    int min_distance = MEM_SIZE;
    int best_distance = 0;

    for (int i = 0; resources->champion_list[i] != NULL; i++) {
        tmp = calculate_distance(pos,
            resources->champion_list[i]->load_address);
        if (tmp < min_distance) {
            min_distance = tmp;
        }
    }
    if (min_distance > best_distance) {
        best_distance = min_distance;
        (*best_position) = pos;
    }
}

void set_spawn_to_farthest(resources_t *resources, champion_t *champion)
{
    static int best_position = 0;
    int arena_pos = 0;
    static int cmp = 1;

    if (cmp == 1)
        for (int pos = 0; pos < MEM_SIZE; pos++)
            find_farthest_point(resources, champion, &best_position, pos);
    champion->load_address = cmp * (best_position % resources->nb_champion);
    champion->processes->pc = champion->load_address;
    printf("resource nb_champ = %d\n", resources->nb_champion);
    printf("best pos = %d\n", best_position);
    printf("%d\n", champion->load_address);
    for (int i = 0; i < champion->prog_size; i++) {
        arena_pos = (best_position + i) % MEM_SIZE;
        resources->arena[arena_pos] = champion->code[i];
    }
    cmp++;
}

void deploy_champions(resources_t *resources)
{
    for (int i = 0; resources->champion_list[i] != NULL; i++) {
        if (resources->champion_list[i]->load_address != -1) {
            set_spawn_to_load_address(resources, resources->champion_list[i]);
        }
    }
    for (int i = 0; resources->champion_list[i] != NULL; i++) {
        if (resources->champion_list[i]->load_address == -1) {
            set_spawn_to_farthest(resources, resources->champion_list[i]);
        }
    }
}
