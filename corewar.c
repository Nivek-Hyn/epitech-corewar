/*
** EPITECH PROJECT, 2025
** project.c
** File description:
** project, Hatim me doit 1 rolls
*/

#include "project.h"

void print_info(void)
{
    printf("USAGE\n./corewar [-dump nbr_cycle] "
        "[[-n prog_number] [-a load_address] prog_name]"
        " ...\nDESCRIPTION\n-dump nbr_cycle dumps the "
        "memory after the nbr_cycle execution (if the round "
        "isn't already over) with the following format: 32"
        " bytes/line in hexadecimal (A0BCDEFE1DD3...) -n "
        "prog_number sets the next program's number. By "
        "default, the first free number in the parameter "
        "order\n-n prog_number sets the next program's "
        "number. By default, the first free number in the "
        "parameter order\n-a load_address sets the next program'"
        "s loading address. When no address is specified, "
        "optimize the addresses so that the processes are as "
        "far away from each other as possible. The "
        "addresses are MEM_SIZE modulo.\n");
}

int check_args(int argc, char **argv)
{
    if (!argv[1])
        return 1;
    if (my_strcmp(argv[1], "-h") == 0) {
        print_info();
        return 2;
    }
    return 0;
}

int corewar(resources_t *resources, int argc, char **argv)
{
    for (int i = 1; i < argc; i++) {
        if (parse_command_arg(resources, argc, argv, &i) == -1)
            return -1;
    }
    deploy_champions(resources);
    run_corewar(resources);
    return 0;
}

int main(int argc, char **argv)
{
    resources_t *resources = malloc(sizeof(resources_t));
    int checked_args = check_args(argc, argv);

    if (check_malloc(resources, "resources: Malloc Failed.\n") == -1)
        return 84;
    if (checked_args == 1) {
        return 84;
    } else if (checked_args == 2) {
        return 0;
    }
    if (initialize_resources(resources) == -1) {
        free_all(resources);
        return 84;
    }
    if (corewar(resources, argc, argv) == -1) {
        free_all(resources);
        return 84;
    }
    free_all(resources);
    return 0;
}
