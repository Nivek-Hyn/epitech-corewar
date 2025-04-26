/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** parse_command_arg
*/

#include "project.h"

int check_flags_two(resources_t *resources, int argc, char **argv, int i)
{
    if (my_strcmp(&argv[i][1], "a") == 0) {
        resources->flags->a++;
        if (argc > i + 1 && !is_number(argv[i + 1]))
            return -1;
        if (argc <= i + 1)
            return -1;
        if (argc > i + 1)
            resources->flags->load_address = my_atoi(argv[i + 1]);
    }
    return 0;
}

int check_flags(resources_t *resources, int argc, char **argv, int i)
{
    if (my_strcmp(&argv[i][1], "dump") == 0) {
        resources->flags->dump++;
        if (argc > i + 1) {
            resources->nbr_cycle = my_atoi(argv[i + 1]);
        } else {
            return -1;
        }
    }
    if (my_strcmp(&argv[i][1], "n") == 0) {
        resources->flags->n++;
        if (argc > i + 1 && !is_number(argv[i + 1]))
            return -1;
        if (argc <= i + 1)
            return -1;
        if (argc > i + 1)
            resources->flags->prog_number = my_atoi(argv[i + 1]);
    }
    return check_flags_two(resources, argc, argv, i);
}

static int flags_errors(resources_t *resources, char **argv, int i)
{
    if (resources->flags->dump != 1)
        return -1;
    if (resources->flags->a + resources->flags->n > 2)
        return -1;
    if (i == 1 && argv[i + 1] && is_number(argv[i + 1]) != 1)
        return -1;
    return 0;
}

void reset_flags(resources_t *resources)
{
    resources->flags->n = 0;
    resources->flags->a = 0;
}

int parse_champion(resources_t *resources, char **argv, int i)
{
    resources->nb_champion++;
    resources->champion_list = realloc(resources->champion_list,
        sizeof(champion_t *) * (resources->nb_champion + 1));
    resources->champion_list[resources->nb_champion - 1] =
        malloc(sizeof(champion_t));
    if (check_malloc(resources->champion_list[resources->nb_champion - 1],
            "champion_list[i]: Malloc Failed.\n") == -1)
        return -1;
    resources->champion_list[resources->nb_champion] = NULL;
    reset_flags(resources);
    if (read_file(resources,
            resources->champion_list[resources->nb_champion - 1],
                argv[i]) == -1)
        return -1;
    return 0;
}

int parse_command_arg(resources_t *resources, int argc, char **argv, int *i)
{
    if (argv[*i][0] == '-') {
        if (check_flags(resources, argc, argv, *i) == -1)
            return -1;
        if (flags_errors(resources, argv, *i) == -1)
            return -1;
        (*i)++;
        return 0;
    }
    if (argv[*i][0] != '-') {
        if (parse_champion(resources, argv, *i) == -1)
            return -1;
    }
    return 0;
}
