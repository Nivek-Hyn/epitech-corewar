/*
** EPITECH PROJECT, 2024
** B-CPE-100-MAR-1-1-cpoolday13-nathan.muzay
** File description:
** hexa
*/
#include "../../include/corewar.h"




int my_put_unsigned(unsigned long int nb)
{
    if (nb < 0){
        nb = 4294967296 + nb;
        my_put_unsigned(nb);
    }
    if (nb >= 10) {
        my_put_unsigned(nb / 10);
    }
    my_putchar((nb % 10) + 48);
    return 0;
}
