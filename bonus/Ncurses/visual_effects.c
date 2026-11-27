/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** visual_effects
*/

#include "project.h"

/*
** 256-colour palette, one row per champion: base, glow (fresh write),
** dim (old trail) and the colour behind a process cursor.
*/
static const short palette[4][3] = {
    {203, 224, 131},
    {78, 157, 29},
    {221, 230, 136},
    {75, 153, 25},
};

void initialize_rich_colors(graphical_t *graphical)
{
    graphical->rich_colors = (COLORS >= 256 && COLOR_PAIRS >= 64);
    if (!graphical->rich_colors)
        return;
    init_pair(40, 236, COLOR_BLACK);
    init_pair(41, COLOR_BLACK, 255);
    for (int c = 0; c < 4; c++) {
        init_pair(42 + c * 4, palette[c][0], COLOR_BLACK);
        init_pair(43 + c * 4, palette[c][1], COLOR_BLACK);
        init_pair(44 + c * 4, palette[c][2], COLOR_BLACK);
        init_pair(45 + c * 4, COLOR_BLACK, palette[c][1]);
    }
}

int champion_index(resources_t *resources, int prog_number)
{
    for (int i = 0; resources->champion_list[i] != NULL; i++) {
        if (resources->champion_list[i]->prog_number == prog_number)
            return i;
    }
    return -1;
}

void update_visual_effects(resources_t *resources, graphical_t *graphical)
{
    process_t *process = NULL;

    for (int i = 0; i < MEM_SIZE; i++) {
        graphical->cursor[i] = 0;
        if (resources->heat[i] > 0)
            resources->heat[i]--;
    }
    for (int i = 0; resources->champion_list[i] != NULL; i++) {
        if (resources->champion_list[i]->pulse > 0)
            resources->champion_list[i]->pulse--;
        process = resources->champion_list[i]->processes;
        for (; process != NULL; process = process->next)
            graphical->cursor[process->pc] |= (process->alive == 1);
    }
}

static int basic_attributes(int index, int heat, int cursor)
{
    if (index < 0)
        return COLOR_PAIR(1) | A_DIM;
    if (cursor)
        return COLOR_PAIR(10 + index % 6) | A_BOLD;
    if (heat > 0)
        return COLOR_PAIR(2 + index % 6) | A_BOLD;
    return COLOR_PAIR(2 + index % 6);
}

/*
** A byte is drawn brighter the more recently it was written, so attacks
** leave a glowing trail; the byte under a process is shown inverted.
*/
int cell_attributes(resources_t *resources, graphical_t *graphical, int i)
{
    int index = champion_index(resources, resources->owner[i]);
    int heat = resources->heat[i];

    if (!graphical->rich_colors || index >= 4)
        return basic_attributes(index, heat, graphical->cursor[i]);
    if (graphical->cursor[i])
        return COLOR_PAIR(45 + index * 4) | A_BOLD;
    if (index < 0)
        return COLOR_PAIR(40);
    if (heat > HEAT_MAX / 2)
        return COLOR_PAIR(43 + index * 4) | A_BOLD;
    if (heat > 0)
        return COLOR_PAIR(42 + index * 4) | A_BOLD;
    if (resources->arena[i] == 0)
        return COLOR_PAIR(44 + index * 4);
    return COLOR_PAIR(42 + index * 4);
}
