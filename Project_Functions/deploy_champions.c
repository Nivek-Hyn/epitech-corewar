/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** deploy_champions
*/

#include "project.h"

void set_spawn_to_load_adress(resources_t *resources, champion_t *champion)
{
    for (int i = 0; i < MEM_SIZE; i++) {
        if (i == champion->load_address) {
            for (int j = 0; j != my_strlen(champion->code); i++) {
                resources->arena[i] = champion->code[j];
            }
        }
    }
}

int calculate_distance(int pos1, int pos2)
{
    int distance;
    
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
    int best_distance = MEM_SIZE;
    int tmp;

    for (int i = 0; resources->champion_list[i] != NULL; i++) {
        for (int j = 0; resources->champion_list[j] != NULL; j++) {
            tmp = calculate_distance(resources->champion_list[i]->load_address, resources->champion_list[j]->load_address);
            if (tmp < best_distance) {
                best_distance = tmp;
            }
        }
    }
    for (int i = 0; i < MEM_SIZE; i++) {
        if (i == best_distance) {
            for (int j = 0; j != my_strlen(champion->code); i++) {
                resources->arena[i] = champion->code[j];
            }
        }
    }
}

void deploy_champions(resources_t *resources)
{
    // for (int i = 0; resources->champion_list[i] != NULL; i++) {
    //     if (resources->champion_list[i]->load_address != -1) {
    //         set_spawn_to_load_adress(resources, resources->champion_list[i]);
    //     }
    // }
    // for (int i = 0; resources->champion_list[i] != NULL; i++) {
    //     if (resources->champion_list[i]->load_address != -1) {
    //         set_spawn_to_load_adress(resources, resources->champion_list[i]);
    //     }
    // }
}
