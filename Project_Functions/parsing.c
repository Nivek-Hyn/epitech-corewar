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

int check_validity(champion_t *champion, char *champion_file)
{
    if (!champion)
        return -1;
    initialize_champion(champion);
    if (!(my_strstr(champion_file, ".cor")))
        return -1;
}

int check_magic_number(FILE *file, champion_t *champion)
{
    int magic_number = 0;

    if (fread(&magic_number, sizeof(int), 1, file) != 1) {
        fclose(file);
        return -1;
    }
    magic_number = convert_big_endian_to_little_endian(magic_number);
    if (magic_number != COREWAR_EXEC_MAGIC)
        return -1;
    return 0;
}

int fill_champion_name(FILE *file, champion_t *champion)
{
    champion->name = malloc(sizeof(char) * PROG_NAME_LENGTH);
    if (check_malloc(champion->name, "champion->name: Malloc Failed.\n") == -1)
        return -1;
    if (fread(champion->name, sizeof(char),
        PROG_NAME_LENGTH, file) != PROG_NAME_LENGTH) {
        fclose(file);
        return -1;
    }
    fseek(file, 4, SEEK_CUR);
    return 0;
}

int fill_champion_prog_size(FILE *file, champion_t *champion)
{
    if (fread(&(champion->prog_size), sizeof(int), 1, file) != 1) {
        fclose(file);
        return -1;
    }
    champion->prog_size = convert_big_endian_to_little_endian(champion->prog_size);
    return 0;
}

int fill_champion_comment(FILE *file, champion_t *champion)
{
    champion->comment = malloc(sizeof(char) * COMMENT_LENGTH);
    if (check_malloc(champion->comment,
        "champion->comment: Malloc Failed.\n") == -1)
        return -1;
    if (fread(champion->comment, sizeof(char),
        COMMENT_LENGTH, file) != COMMENT_LENGTH) {
        fclose(file);
        return -1;
    }
    return 0;
}

int read_file(resources_t *resources, champion_t *champion,
    char *champion_file)
{
    FILE *file = NULL;

    if (check_validity(champion, champion_file) == -1)
        return -1;
    file = fopen(champion_file, "rb");
    if (!file)
        return -1;
    if (check_magic_number(file, champion) == -1)
        return -1;
    champion->prog_number = resources->flags->prog_number;
    champion->load_address = resources->flags->load_address;
    if (fill_champion_name(file, champion) == -1)
        return -1;
    if (fill_champion_prog_size(file, champion) == -1)
        return -1;
    if (fill_champion_comment(file, champion) == -1)
        return -1;
    printf("name: %s\ncomment: %s\nprog_size: %d\nprog_number: %d\nload_adress: %d\n", champion->name, champion->comment, champion->prog_size, champion->prog_number, champion->load_address);
    fclose(file);
    return 0;
}
