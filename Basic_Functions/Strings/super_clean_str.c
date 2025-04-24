/*
** EPITECH PROJECT, 2025
** super_clean_str.c
** File description:
** clean any non desired character at the chosen section
*/

#include "my.h"

int all_contain_char(char *str, char *characters)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (contain_char(characters, str[i]) != 1)
            return 0;
    }
    return 1;
}

char *super_cleaning_str(char *str, char *to_clean, char *sections, int count)
{
    int toggle = 0;
    char *cleaned_str = malloc(sizeof(char) * (count + 1));
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (contain_char(to_clean, str[i]) != 1) {
            toggle = 1;
            cleaned_str[j] = str[i];
            j++;
        }
        if ((contain_char(to_clean, str[i]) == 1 && toggle == 0 && sections[0]
            != '1') || (contain_char(to_clean, str[i]) == 1 && toggle == 1 &&
            sections[1] != '1' && all_contain_char(&str[i], to_clean) != 1) ||
            (all_contain_char(&str[i], to_clean) == 1 && sections[2] != '1')) {
            cleaned_str[j] = str[i];
            j++;
        }
    }
    cleaned_str[j] = '\0';
    return cleaned_str;
}

char *super_clean_str(char *str, char *to_clean, char *sections)
{
    int toggle = 0;
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (contain_char(to_clean, str[i]) != 1) {
            toggle = 1;
            count++;
        }
        if (contain_char(to_clean, str[i]) == 1 && toggle == 0 &&
            sections[0] != '1')
            count++;
        if (contain_char(to_clean, str[i]) == 1 && toggle == 1 &&
            sections[1] != '1' && all_contain_char(&str[i], to_clean) != 1)
            count++;
        if (all_contain_char(&str[i], to_clean) == 1 && sections[2] != '1')
            count++;
    }
    return super_cleaning_str(str, to_clean, sections, count);
}
