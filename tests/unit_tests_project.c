/*
** EPITECH PROJECT, 2024
** Unit Tests
** File description:
** Testing my Project
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "project.h"

Test(mega_write, hello_world, .init = cr_redirect_stdout)
{
    char *str = "World";

    mega_write(STDOUT_FILENO, "Hello %s", str);
    cr_assert_stdout_eq_str("Hello World");
}

Test(magic_num, magic_number)
{
    FILE *file = fopen("test_champions/abel.cor", "rb");
    int magic_number = 0;

    cr_assert(file, "Erreur : impossible d'ouvrir le fichier abel.cor");
    if (fread(&magic_number, sizeof(int), 1, file) != 1) {
        fclose(file);
        cr_assert_fail("Erreur : lecture du magic number échouée");
    }
    fclose(file);
    magic_number = convert_big_endian_to_little_endian(magic_number);
    cr_assert_eq(magic_number, COREWAR_EXEC_MAGIC,
        "Magic number incorrect : attendu 0x%x, obtenu 0x%x",
        COREWAR_EXEC_MAGIC, magic_number);
}

Test(prog_name_test, prog_name)
{
    FILE *file = fopen("test_champions/abel.cor", "rb");
    char *name = malloc(sizeof(char) * PROG_NAME_LENGTH);
    size_t returned;

    cr_assert(file, "Erreur : impossible d'ouvrir le fichier abel.cor");
    cr_assert(name, "Erreur : allocation du nom échouée");
    fseek(file, 4, SEEK_SET);
    returned = fread(name, sizeof(char), PROG_NAME_LENGTH, file);
    cr_assert_eq(returned, PROG_NAME_LENGTH,
        "Erreur de lecture du nom : attendu %d octets, obtenu %ld",
        PROG_NAME_LENGTH, returned);
    fclose(file);
    free(name);
}

Test(comment_test, comment, .init = cr_redirect_stdout)
{
    FILE *file = fopen("test_champions/abel.cor", "rb");
    char *comment = malloc(sizeof(char) * COMMENT_LENGTH);
    size_t returned;
    int to_jump = 4 + PROG_NAME_LENGTH + 4 + 4;

    cr_assert(file, "Erreur : impossible d'ouvrir le fichier abel.cor");
    cr_assert(comment, "Erreur : allocation du nom échouée");
    fseek(file, to_jump, SEEK_SET);
    returned = fread(comment, sizeof(char), COMMENT_LENGTH, file);
    cr_assert_eq(returned, COMMENT_LENGTH,
        "Erreur de lecture du nom : attendu %d octets, obtenu %ld",
        COMMENT_LENGTH, returned);
    fclose(file);
    free(comment);
}

Test(prog_size_test, prog_size, .init = cr_redirect_stdout)
{
    FILE *file = fopen("test_champions/abel.cor", "rb");
    char *prog_size;
    size_t returned;
    int to_jump = 4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4;

    cr_assert(file, "Erreur : impossible d'ouvrir le fichier abel.cor");
    fseek(file, to_jump, SEEK_SET);
    returned = fread(&prog_size, sizeof(int), 1, file);
    cr_assert_eq(to_jump, 2192,
        "Erreur de prog_size : attendu %d octets, obtenu %ld",
        2192, to_jump);
    fclose(file);
}