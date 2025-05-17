/*
** EPITECH PROJECT, 2025
** B-CPE-200-MAR-2-1-corewar-kevin.huynh
** File description:
** run_instruction
*/

#include "project.h"

void exec_aff_bonus(resources_t *resources, champion_t *champion,
    process_t *process)
{
    uint8_t coding_byte = resources->arena[(process->pc + 1) % MEM_SIZE];
    uint8_t type1 = (coding_byte >> 6) & 0b11;
    int value;
    int reg;

    if (type1 != 0b01)
        return;
    reg = resources->arena[(process->pc + 2) % MEM_SIZE];
    if (reg < 1 || reg > REG_NUMBER)
        return;
    value = process->registers[reg - 1];
}

void exec_live_bonus(resources_t *resources, champion_t *champion,
    process_t *process)
{
    unsigned int prog_number = (unsigned int)get_parameter_value(
        resources, (process->pc + 1) % MEM_SIZE, 4);

    process->alive = 1;
    process->live = true;
    resources->total_lives++;
}

void run_instruction_graphical(resources_t *resources, champion_t *champion,
    process_t *process)
{
    void (*instructions[NBR_INSTRUCTIONS])
        (resources_t *, champion_t *, process_t *) =
        {exec_live_bonus, exec_ld, exec_st, exec_add, exec_sub, exec_and,
            exec_or, exec_xor, exec_zjmp, exec_ldi, exec_sti, exec_fork,
                exec_lld, exec_lldi, exec_lfork, exec_aff_bonus};

    for (int i = 0; op_tab[i].code != 0; i++) {
        if (op_tab[i].code == process->current_instruction) {
            instructions[i](resources, champion, process);
        }
    }
}
