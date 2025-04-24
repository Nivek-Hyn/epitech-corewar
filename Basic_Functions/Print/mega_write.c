/*
** EPITECH PROJECT, 2025
** mega_write.c
** File description:
** exactly like mini_printf but much faster
*/

#include "my.h"

static void concat_arg_to_str_two(char *str, char c, va_list args, int *j)
{
    char *tmp = NULL;

    switch (c) {
        case 'd':
        case 'i':
            tmp = nbr_to_str(va_arg(args, int));
            my_strcat(str, tmp);
            *j += my_strlen(tmp);
            break;
        case '%':
            my_strcat(str, "%");
            (*j)++;
            break;
        default:
            break;
    }
    if (tmp)
        free(tmp);
}

static void concat_arg_to_str(char *str, char c, va_list args, int *j)
{
    char *tmp = NULL;

    switch (c) {
        case 'c':
            tmp = char_to_string(va_arg(args, int));
            my_strcat(str, tmp);
            (*j)++;
            break;
        case 's':
            tmp = my_strdup(va_arg(args, char *));
            my_strcat(str, tmp);
            *j += my_strlen(tmp);
            break;
        default:
            concat_arg_to_str_two(str, c, args, j);
            break;
    }
    if (tmp)
        free(tmp);
}

static char *create_full_str(const char *format, va_list args, int len)
{
    char *str = malloc(sizeof(char) * (len + 1));
    int i = 0;
    int j = 0;

    if (!str)
        return NULL;
    str[0] = '\0';
    str[len] = '\0';
    for (i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            concat_arg_to_str(str, format[i + 1], args, &j);
            i++;
        } else {
            str[j] = format[i];
            str[j + 1] = '\0';
            j++;
        }
    }
    return str;
}

static int arg_len_two(char c, va_list args)
{
    int count = 0;
    char *tmp = NULL;

    switch (c) {
        case 'd':
        case 'i':
            tmp = nbr_to_str(va_arg(args, int));
            count += my_strlen(tmp);
            break;
        case '%':
            count++;
            break;
        default:
            break;
    }
    if (tmp)
        free(tmp);
    return count;
}

static int arg_len(char c, va_list args)
{
    int count = 0;

    switch (c) {
        case 'c':
            va_arg(args, int);
            count++;
            break;
        case 's':
            count += my_strlen(va_arg(args, char *));
            break;
        default:
            return arg_len_two(c, args);
    }
    return count;
}

void mega_write(int fd, const char *format, ...)
{
    va_list args;
    int len = 0;
    char *str = NULL;

    va_start(args, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            len += arg_len(format[i + 1], args);
            i++;
        } else {
            len++;
        }
    }
    va_end(args);
    va_start(args, format);
    str = create_full_str(format, args, len);
    my_write(fd, str);
    free(str);
    va_end(args);
}
