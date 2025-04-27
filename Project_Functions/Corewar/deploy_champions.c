/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** deploy_champions
*/

#include "project.h"

void set_spawn_to_load_adress(resources_t *resources, champion_t *champion)
{
    int arena_pos = 0;

    for (int i = 0; i < my_strlen(champion->code); i++) {
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

void set_spawn_to_farthest(resources_t *resources, champion_t *champion)
{
    int best_distance = 0;
    int best_position = 0;
    int tmp = 0;
    int min_distance = 0;
    int arena_pos = 0;

    for (int pos = 0; pos < MEM_SIZE; pos++) {
        min_distance = MEM_SIZE;
        for (int i = 0; resources->champion_list[i] != NULL; i++) {
            tmp = calculate_distance(pos, resources->champion_list[i]->load_address);
            if (tmp < min_distance) {
                min_distance = tmp;
            }
        }
        if (min_distance > best_distance) {
            best_distance = min_distance;
            best_position = pos;
        }
    }
    champion->load_address = best_position;
    for (int i = 0; i < my_strlen(champion->code); i++) {
        arena_pos = (best_position + i) % MEM_SIZE;
        resources->arena[arena_pos] = champion->code[i];
    }
}

void deploy_champions(resources_t *resources)
{
    for (int i = 0; resources->champion_list[i] != NULL; i++) {
        if (resources->champion_list[i]->load_address != -1) {
            set_spawn_to_load_adress(resources, resources->champion_list[i]);
        }
    }
    for (int i = 0; resources->champion_list[i] != NULL; i++) {
        if (resources->champion_list[i]->load_address == -1) {
            set_spawn_to_farthest(resources, resources->champion_list[i]);
        }
    }
}
