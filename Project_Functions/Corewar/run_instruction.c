/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** run_instruction
*/

#include "project.h"

void run_instruction(resources_t *resources, champion_t *champion,
    process_t *process)
{
    void (*instructions[NBR_INSTRUCTIONS])
        (resources_t *, champion_t *, process_t *) =
        {exec_live, exec_ld, exec_add, exec_sub, exec_and, exec_or,
            exec_xor, exec_zjmp, exec_ldi, exec_sti, exec_fork, exec_lld,
                exec_lldi, exec_lfork, exec_aff};

    for (int i = 0; op_tab[i].code != 0; i++) {
        if (op_tab[i].code == process->current_instruction) {
            //instructions[i](resources, champion, process);
            printf("Hello World !\n");
        }
    }
}
