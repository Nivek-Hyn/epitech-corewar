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

    champion->processes->pc = champion->load_address;
    for (int i = 0; i < champion->prog_size; i++) {
        arena_pos = (champion->load_address + i) % MEM_SIZE;
        resources->arena[arena_pos] = champion->code[i];
        resources->owner[arena_pos] = champion->prog_number;
    }
}

static int calculate_distance(int pos1, int pos2)
{
    int direct_distance = pos1 - pos2;
    int wrap_distance;

    if (direct_distance < 0)
        direct_distance *= -1;
    wrap_distance = MEM_SIZE - direct_distance;
    if (direct_distance < wrap_distance) {
        return direct_distance;
    } else {
        return wrap_distance;
    }
}

void check_and_change_position(resources_t *resources, int pos,
    int *distance, int *min_distance)
{
    for (int i = 0; resources->champion_list[i] != NULL; i++) {
        if (resources->champion_list[i]->load_address == -1) {
            continue;
        }
        (*distance) = calculate_distance(pos,
            resources->champion_list[i]->load_address);
        if ((*distance) < (*min_distance)) {
            (*min_distance) = (*distance);
        }
    }
}

static int find_optimal_position(resources_t *resources)
{
    int best_pos = 0;
    int best_min_distance = -1;
    int min_distance = MEM_SIZE;
    int distance;

    for (int pos = 0; pos < MEM_SIZE; pos++) {
        min_distance = MEM_SIZE;
        check_and_change_position(resources, pos, &distance, &min_distance);
        if (min_distance > best_min_distance) {
            best_min_distance = min_distance;
            best_pos = pos;
        }
    }
    return best_pos;
}

static void set_spawn_to_farthest(resources_t *resources, champion_t *champion)
{
    int optimal_pos = find_optimal_position(resources);

    champion->load_address = optimal_pos;
    champion->processes->pc = champion->load_address;
    set_spawn_to_load_address(resources, champion);
}

void set_prog_number(resources_t *resources, champion_t *champion)
{
    int max = MAX_SIZE;
    int cmp;

    for (int i = 0; i < resources->nb_champion; i++) {
        if (resources->champion_list[i]->prog_number != -1) {
            cmp = resources->champion_list[i]->prog_number;
        }
        if (cmp < max) {
            max = cmp;
        }
    }
    champion->prog_number = max - 1;
}

void deploy_champions(resources_t *resources)
{
    int spacing;

    for (int i = 0; i < resources->nb_champion; i++) {
        if (resources->champion_list[i]->load_address != -1) {
            set_spawn_to_load_address(resources, resources->champion_list[i]);
        }
    }
    for (int i = 0; i < resources->nb_champion; i++) {
        if (resources->champion_list[i]->load_address == -1) {
            set_spawn_to_farthest(resources, resources->champion_list[i]);
        }
    }
}
