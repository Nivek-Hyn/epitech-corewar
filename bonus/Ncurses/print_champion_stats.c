/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** print_champion_stats
*/

#include "project.h"

static int name_attributes(graphical_t *graphical, int index, int pulse)
{
    int color_pair = 2 + index % 6;

    if (graphical->rich_colors && index < 4)
        color_pair = (pulse > 0) ? 45 + index * 4 : 42 + index * 4;
    else if (pulse > 0)
        return COLOR_PAIR(10 + index % 6) | A_BOLD;
    return COLOR_PAIR(color_pair) | A_BOLD;
}

static void print_territory_bar(graphical_t *graphical, int y,
    int territory, int attributes)
{
    int owned = graphical->owned_bytes;
    int width = (owned > 0) ? territory * 30 / owned : 0;

    if (width > 30)
        width = 30;
    if (territory > 0 && width == 0)
        width = 1;
    wattron(graphical->info_win, attributes);
    for (int x = 0; x < width; x++)
        mvwaddch(graphical->info_win, y, 3 + x, ACS_CKBOARD);
    wattroff(graphical->info_win, attributes);
    mvwprintw(graphical->info_win, y, 35, "%5d bytes", territory);
}

/*
** One block per champion: the name flashes on each live, followed by the
** number of living processes and a bar of the memory it currently owns.
*/
void print_champion_stats(graphical_t *graphical, resources_t *resources,
    int index, int y)
{
    champion_t *champion = resources->champion_list[index];
    int processes = count_processes(champion);
    int attributes = name_attributes(graphical, index, champion->pulse);

    graphical->owned_bytes = count_owned(resources);

    wattron(graphical->info_win, attributes);
    mvwprintw(graphical->info_win, y, 1, " %d %s ",
        champion->prog_number, champion->name);
    wattroff(graphical->info_win, attributes);
    if (processes == 0)
        mvwprintw(graphical->info_win, y, 30, "      OUT");
    else
        mvwprintw(graphical->info_win, y, 30, "%3d process%s", processes,
            (processes > 1) ? "es" : "");
    print_territory_bar(graphical, y + 1, count_territory(resources,
        champion->prog_number), name_attributes(graphical, index, 0));
}
