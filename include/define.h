/*
** EPITECH PROJECT, 2024
** my_isneg
** File description:
** my_isneg.c
*/

#ifndef DEFINE_H_
    #define DEFINE_H_

    #define ERROR_NUM 84
    #define MAX_SIZE 2147483647
    #define SUCCEED 0
    #define NBR_INSTRUCTIONS 16
    #define FORMULA_OFFSET (process->pc + 2) % MEM_SIZE, 2
    #define FORMULA_VALUE (process->pc + (offset % IDX_MOD)) % MEM_SIZE, 4
    #define FORMULA_SECOND (process->pc + (offset % IDX_MOD)) % MEM_SIZE, 4
    #define VALUE_GET params->pc_offset, process, resources
    #define OFS resources->arena[(process->pc + params->pc_offset) % MEM_SIZE]

#endif /* DEFINE_H_ */
