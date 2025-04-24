/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** parsing
*/

#include "../include/project.h"
#include "../include/corewar.h"

uint32_t convert_big_endian_to_little_endian(uint32_t Big_Endian)
{
    uint32_t Little_Endian = 0;

    Little_Endian |= (Big_Endian & 0x000000FF) << 24;
    Little_Endian |= (Big_Endian & 0x0000FF00) << 8;
    Little_Endian |= (Big_Endian & 0x00FF0000) >> 8;
    Little_Endian |= (Big_Endian & 0xFF000000) >> 24;
    return Little_Endian;
}

int read_file(char **argv)
{
    FILE *file = fopen(argv[1], "rb");
    int magic_number = 0;

    if (fread(&magic_number, sizeof(int), 1, file) != 1) {
        fclose(file);
        return 84;
    }
    magic_number = convert_big_endian_to_little_endian(magic_number);
    if (magic_number == COREWAR_EXEC_MAGIC) {
        mega_write(1, "Valid magic number!\n");
    } else {
        mega_write(1, "Invalid magic number!\n");
    }
    char *prog_name = malloc(sizeof(char) * PROG_NAME_LENGTH);
    if (fread(prog_name, sizeof(char), PROG_NAME_LENGTH, file) != PROG_NAME_LENGTH) {
        fclose(file);
        return 84;
    }
    mega_write(1, "prog_name: %s\n", prog_name);
    fseek(file, 4, SEEK_CUR);
    int prog_size = 0;
    if (fread(&prog_size, sizeof(int), 1, file) != 1) {
        fclose(file);
        return 84;
    }
    prog_size = convert_big_endian_to_little_endian(prog_size);
    mega_write(1, "prog_size: %d\n", prog_size);
    char *comment = malloc(sizeof(char) * COMMENT_LENGTH);
    if (fread(comment, sizeof(char), COMMENT_LENGTH, file) != COMMENT_LENGTH) {
        fclose(file);
        return 84;
    }
    mega_write(1, "comment: %s\n", comment);
    fclose(file);
    return 0;
}