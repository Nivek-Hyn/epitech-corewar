##
## EPITECH PROJECT, 2024
## make
## File description:
## makefile
##

CC = gcc
AR = ar
CFLAGS = -Iinclude -I./csfml/include
SRC_LIB = $(wildcard lib/my/*.c)
OBJ_LIB = $(SRC_LIB:.c=.o)
MY_H = corewar.h
NAME = corewar
SRC_PROG = $(shell find . -type f -name "*.c")
OBJ_PROG = $(SRC_PROG:.c=.o)

all: libmy.a $(NAME)

libmy.a: $(OBJ_LIB)
	$(AR) rcs libmy.a $(OBJ_LIB)

$(NAME): libmy.a $(OBJ_PROG)
	$(CC) -o $(NAME) $(OBJ_PROG)

clean:
	rm -f $(OBJ_LIB) $(OBJ_PROG)

test: all

fclean: clean
	rm -f libmy.a $(NAME)

re: fclean all clean

coding_style: clean
	cd ../coding-style-checker/ \
	&& ./coding-style.sh ../B-CPE-200-MAR-2-1-corewar-kevin.huynh/ \
	&& cd ../B-CPE-200-MAR-2-1-corewar-kevin.huynh/ \
	&& make \
	&& clear \
	&& cd ../coding-style-checker/ \
	&& cat coding-style-reports.log

valgrind: fclean
	@(gcc $(SRC) -g3 -o mysh -I../includes -lm)

push: fclean
	@(find . -type f -name "#.#" -delete -o -name "*~" -delete)
	@(git add .)
	@(git commit -m "[REMOVE] -f removed")
	@(git push)
