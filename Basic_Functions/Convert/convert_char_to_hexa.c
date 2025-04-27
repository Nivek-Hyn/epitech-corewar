/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** convert_char_to_hexa
*/

#include "my.h"

void convert_char_to_hexa(char c, char *dest)
{
    int nb = (int)c;
    int high = nb / 16;
    int low = nb % 16;

    if (high < 10)
        dest[0] = '0' + high;
    else
        dest[0] = 'A' + (high - 10);
    if (low < 10)
        dest[1] = '0' + low;
    else
        dest[1] = 'A' + (low - 10);
    dest[2] = '\0';
}
