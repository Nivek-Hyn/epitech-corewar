/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** convert_big_endian_to_little_endian
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
