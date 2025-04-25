/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** parsing
*/

#include "project.h"

uint32_t convert_big_endian_to_little_endian(uint32_t Big_Endian)
{
    uint32_t Little_Endian = 0;

    Little_Endian |= (Big_Endian & 0x000000FF) << 24;
    Little_Endian |= (Big_Endian & 0x0000FF00) << 8;
    Little_Endian |= (Big_Endian & 0x00FF0000) >> 8;
    Little_Endian |= (Big_Endian & 0xFF000000) >> 24;
    return Little_Endian;
}

int check_validity(champion_t *champion, char **argv)
{
    if (!champion || !champion->name)
        return -1;
    if (!(my_strstr(champion->name, ".cor")))
        return -1;
}

int read_file(champion_t *champion, char **argv)
{
    if (check_validity(champion, argv) == -1)
        return -1;
    return 0;
}

// int read_file(resources_t *resources, char **argv)
// {
//     FILE *file = fopen(argv[1], "rb");
//     int magic_number = 0;

//     if (fread(&magic_number, sizeof(int), 1, file) != 1) {
//         fclose(file);
//         return -1;
//     }
//     magic_number = convert_big_endian_to_little_endian(magic_number);
//     if (magic_number != COREWAR_EXEC_MAGIC)
//         return -1;
//     char *prog_name = malloc(sizeof(char) * PROG_NAME_LENGTH);
//     if (fread(prog_name, sizeof(char),
//          PROG_NAME_LENGTH, file) != PROG_NAME_LENGTH) {
//         fclose(file);
//         return -1;
//     }
//     fseek(file, 4, SEEK_CUR);
//     int prog_size = 0;
//     if (fread(&prog_size, sizeof(int), 1, file) != 1) {
//         fclose(file);
//         return -1;
//     }
//     prog_size = convert_big_endian_to_little_endian(prog_size);
//     char *comment = malloc(sizeof(char) * COMMENT_LENGTH);
//     if (fread(comment, sizeof(char),
//        COMMENT_LENGTH, file) != COMMENT_LENGTH) {
//         fclose(file);
//         return -1;
//     }
//     fclose(file);
//     return 0;
// }
