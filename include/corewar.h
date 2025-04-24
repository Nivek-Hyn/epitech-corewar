/*
** EPITECH PROJECT, 2024
** B-CPE-101-MAR-1-1-myprintf-nathan.muzay
** File description:
** my
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
#include "define.h"
#include "struct.h"
#include "op.h"

#ifndef MY_H_
    #define MY_H_

//Project
int read_file(char **argv);

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

#endif /* !MY_H_ */
