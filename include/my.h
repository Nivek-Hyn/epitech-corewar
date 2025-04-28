/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** contains basic functions
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdint.h>

#ifndef BASIC
    #define BASIC

typedef struct tokenizer {
    char *delim;
    char *token;
    int i;
    int toggle;
    char **delim_tokens;
} tokenizer_t;

// // // Basic Functions:

// Print:
void my_putchar(char c);
void my_putstr(char *str);
void my_putnbr(int nb);
void mini_printf(const char *format, ...);
void clean_str(char *str);
void my_write(int fd, char *str);
void mega_write(int fd, const char *format, ...);
void print_array(char **array, char c);
void print_file(char *file_path);

// Characters:
int is_alpha(char c);
int is_upper(char c);
int is_lower(char c);
int is_digit(char c);
int is_space(char c);
void my_swap(int *a, int *b);

// Strings:
char *my_strdup(char *str);
char *my_special_strdup(int i, char *str, char *delimiter);
int my_strlen(char *str);
int my_special_strlen(int i, char *str, char *delimiter);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strcat_malloc(char *dest, char *src);
char *my_special_strcat(char *str1, int n1, char *str2, int n2);
char *my_strcapitalize(char *str);
char *my_strlowcase(char *str);
char *my_strupcase(char *str);
char *my_strstr(char *str, char const *to_find);
char *my_revstr(char *str);
int my_getnbr(char const *str);
void remove_newline(char *str);
void replace_last_char(char *str, char c);
char *super_clean_str(char *str, char *to_clean, char *sections);

// Arrays:
void my_sort_int_array(int *array, int size);
int array_len(char **array);
char **array_dup(char **array);
void free_array(char **array);

// Linked Lists:

// Numbers:

// Count:
int nbr_of_digits(int nb);
int float_strlen(char *float_str);
int int_strlen(char *int_str);
int count_words(char *str);
int count_lines(char *str);
int count_until_delim(char *str, char *delim);
int count_character(char *str, char c);

// Convert:
int my_atoi(char *str);
char *nbr_to_str(int nb);
char *char_to_string(char c);
char *array_to_string(char **array, char *separator);
void convert_char_to_hexa(char c, char *dest);

// Files:
int fs_open_file(char const *filepath);
int file_size(char *filepath);
char *get_file_content(char *file_path);

// Parsing:
int my_getline(char **line, char *str, int i);
char **my_str_to_word_array(char *str);
char *my_strtok(char *str, char *delim, char *token, int *i);
char *my_strtok_alt(char *str, char *delim, char *token, int *i);
char *my_strtok_r(char *str, char *delim, char *token, int *i);
char *my_strtok_r_alt(char *str, char *delim, char *token, int *i);
char **my_parse(char *str, char *delimiter);
char **my_parse_select(char *str, char *delimiter);
char **my_special_parse(char *str, char *separator,
    char *(*strtok_func)(char *str, char *delim, char *token, int *i));
char **special_parse(char *str, const char *separator);
tokenizer_t *initialize_tokenizer(char *delim, char **delim_tokens);
void free_tokenizer(tokenizer_t *tokenizer);
char *delim_tok(char *str, tokenizer_t *tokenizer);
char *my_str_and_delim_tok(char *str, tokenizer_t *tokenizer);
char **my_special_parse_alt(char *str, tokenizer_t *tokenizer);

// Check:
int check_last_char(char *str, char c);
int check_if_between(char *str, char c);
int contain_char(char *str, char c);
int contain_only_char(char *str, char *c);
int is_int(char *str);
int is_float(char *str);
int is_bool(char *str);
int is_number(char *str);

// Error Handling:
int check_malloc(void *data, char *error_text_display);

// Print Error Output:
void my_putchar_stderr(char c);
void my_putstr_stderr(char *str);
void my_putnbr_stderr(int nb);
void mini_printf_stderr(const char *format, ...);

// Other:
int execute_command(char *command, char **args, char **env);

//lib
bool handle_start_command(char **args, int *start, int i);
bool handle_end_command(char **args, int *end, int i);
char *my_strchr(const char *s, int c);
char *my_int_to_str(int num);
int strlen_lign(char *buff);
int nb_lign(char *str);
int add(void *data, char **args);
int my_getnbr_n(char *const str, int n);
char *nb_to_str(int i);
char *concat_params(int argc, char **argv);
int my_is_prime(int nb);
int my_isalpha(char c);
int len_float(int f);
int my_strcmp(char const *s1, char const *s2);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
void clean_argument(char *arg);
char **copy_char_double(char **env);
char **str_to_array(char *buff);
char **my_str_to_word_array(char *str);
char **my_str_to_word_array_delim(char *str, char delim);
int nb_char(char *str);
int nb_mot(char *str);
char *my_strupcase(char *str);
int my_show_word_array(char *const *tab);
//my_printf
void my_printf(char const *format, ...);
char *my_revstr(char *);
char *my_strcpy(char *, char const *);
int get_precision(const char *str, int *index);
int nb_len(int);
int my_putnbr_hexamaj(unsigned int nb);
int my_putnbr_hexamin(unsigned long int nb);
long unsigned int my_putnbr_octal(unsigned int n);
int my_put_unsigned(unsigned long int nb);
int my_put_float_f(double a, int precision);
//maths
int my_compute_power_it(int nb, int p);
//error_gesting
int error_mess(char *str);

#endif
