/*
** EPITECH PROJECT, 2025
** project.c
** File description:
** project
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

void free_all(resources_t *resources)
{
    free(resources);
}

int main(int argc, char **argv)
{
    resources_t *resources = malloc(sizeof(resources_t));
    int checked_args = check_args(argc, argv);

    if (!resources)
        return 84;
    if (checked_args == 1) {
       return 84;
    } else if (checked_args == 2)
        return 0;
    if (read_file(argv, resources) == 84) {
        free_all(resources);
        return 84;
    }
    free_all(resources);
    return 0;
}
