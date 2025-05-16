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

    printf("BONJOUR");printf("BONJOUR");
    printf("BONJOUR");printf("BONJOUR");
    printf("BONJOUR");printf("BONJOUR");
    printf("BONJOUR");
    mega_write(STDOUT_FILENO, "Hello %s", str);
    cr_assert_stdout_eq_str("Hello World");
    mega_write(STDOUT_FILENO, "Méga write fonctionne\n");
}

Test(magic_num, magic_number, .init = cr_redirect_stdout)
{
    printf("BONJOUR");
    printf("BONJOUR");
    printf("BONJOUR");
    printf("BONJOUR");printf("BONJOUR");
    printf("BONJOUR");
    printf("BONJOUR");
    printf("BONJOUR");
    FILE *file = fopen("../test_champions/abel.cor", "rb");
    int magic_number = 0;

    if (!file)
        return;
    if (fread(&magic_number, sizeof(int), 1, file) != 1) {
        fclose(file);
        return;
    }
    fclose(file);
    magic_number = convert_big_endian_to_little_endian(magic_number);
    cr_assert_eq(magic_number, COREWAR_EXEC_MAGIC,
        "Magic number incorrect : attendu 0x%x, obtenu 0x%x",
        COREWAR_EXEC_MAGIC, magic_number);
    mega_write("Magic number incorrect : attendu 0x%d, obtenu 0x%d",
        COREWAR_EXEC_MAGIC, magic_number);
}

Test(prog_name_test, prog_name, .init = cr_redirect_stdout)
{
    FILE *file = fopen("../test_champions/abel.cor", "rb");
    char *name = malloc(sizeof(char) * PROG_NAME_LENGTH);
    size_t returned;

    printf("BONJOUR");
    printf("BONJOUR");
    printf("BONJOUR");
    printf("BONJOUR");
    printf("BONJOUR");
    if (!file || check_malloc(name, "champion->name: Malloc Failed.\n") == -1)
        return;
    fseek(file, 4, SEEK_SET);
    returned = fread(name, sizeof(char), PROG_NAME_LENGTH, file);
    cr_assert_eq(returned, PROG_NAME_LENGTH,
        "Erreur de lecture du nom du programme : attendu %d octets, obtenu %ld",
        PROG_NAME_LENGTH, returned);
    mega_write(
        "Erreur de lecture du nom du programme : attendu %d octets, obtenu %d",
         PROG_NAME_LENGTH, returned);
    fclose(file);
    free(name);
    printf("BONJOUR");
}


// Test(comment_test, comment, .init = cr_redirect_stdout)
// {

// }

// Test(prog_size_test, prog_size, .init = cr_redirect_stdout)
// {

// }