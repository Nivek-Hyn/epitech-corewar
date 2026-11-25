# Corewar

A virtual machine for Corewar, written in C. Compiled champion programs (`.cor` files) are loaded into a shared circular memory of 6 KB and executed cycle by cycle; each champion tries to stay alive by calling `live` while overwriting the others. The last champion with living processes wins. A bonus build shows the arena live in the terminal with ncurses.

The assembler that compiles champions into `.cor` files was a separate project (Robot Factory) and is not part of this repository.

## Features

- Loads any number of champions from `.cor` files: checks the magic number, reads the name, comment, program size and code.
- `-n` sets a champion's number and `-a` its load address; without `-a`, champions are placed as far apart from each other as possible.
- Cycle loop with `CYCLE_TO_DIE` / `CYCLE_DELTA` / `NBR_LIVE` rules: processes that did not report `live` in time are killed.
- All 16 instructions: `live`, `ld`, `st`, `add`, `sub`, `and`, `or`, `xor`, `zjmp`, `ldi`, `sti`, `fork`, `lld`, `lldi`, `lfork`, `aff`.
- `-dump nbr_cycle` prints the memory after that cycle, 32 bytes per line in hexadecimal, coloured by the champion that wrote each byte.
- Announces the winner at the end of the round.
- Bonus ncurses view (`corewar_bonus`): start menu, scrolling arena coloured by owner, champion info and parameters panels, adjustable speed and pause.

## Build & run

Requires `gcc` and `make`; the bonus also needs `ncurses`.

```sh
make            # builds ./corewar
make bonus      # also builds ./corewar_bonus (ncurses view)
make re         # full rebuild
make fclean     # remove objects, libraries and binaries
```

```sh
./corewar -h
./corewar [-dump nbr_cycle] [[-n prog_number] [-a load_address] prog_name] ...
```

Example with the sample champions:

```sh
./corewar -dump 1000 -n 1 test_champions/abel.cor -n 2 test_champions/bill.cor \
          -n 3 test_champions/pdd.cor -n 4 test_champions/tyron.cor
```

The ncurses view takes the same arguments and must be run from the repository root (it reads `bonus/Ncurses/Corewar.txt`):

```sh
./corewar_bonus test_champions/abel.cor test_champions/bill.cor
```

Controls: `s` start, `Space` pause/resume, `Left`/`Right` change the delay by 10 ms, `Up`/`Down` scroll the arena, `q` quit.

Unit tests use Criterion: `make unit_tests` builds `tests/unit_tests`.

## Project layout

- `corewar.c` - entry point: argument check, usage, setup and run.
- `Project_Functions/` - the virtual machine: parsing, initialization, processes, the cycle loop and one file per instruction.
- `Basic_Functions/` - small C utility library (strings, parsing, printing, conversions), built as `libmy.a`.
- `bonus/` - ncurses front end and its own entry point.
- `include/` - headers, including `op.h` with the VM constants and instruction table.
- `test_champions/` - sample champions, as source (`.s`) and compiled (`.cor`).
- `tests/` - Criterion unit tests.

## Team

Epitech school project, built in a pair. My part was the virtual machine: loading champions, the cycle loop, every instruction, the live checks and the ncurses view.
