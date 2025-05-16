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

Test(mega_write, , .init = cr_redirect_stdout)
{
    char *str = "World";

    mega_write(STDOUT_FILENO, "Hello %s", str);
    cr_assert_stdout_eq_str("Hello World");
}
