##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile for project
##

OBJ_DIR = obj
BASIC_DIR = Basic_Functions
PROJECT_DIR = Project_Functions
INCLUDE_DIR = include
LIB_DIR = Lib

BASIC_SRC = $(wildcard $(BASIC_DIR)/**/*.c $(BASIC_DIR)/*.c)
PROJECT_SRC = $(wildcard $(PROJECT_DIR)/**/*.c $(PROJECT_DIR)/*.c)

BASIC_OBJ = $(patsubst $(BASIC_DIR)/%.c,\
	$(OBJ_DIR)/$(BASIC_DIR)/%.o, $(BASIC_SRC))
PROJECT_OBJ = $(patsubst $(PROJECT_DIR)/%.c,\
	$(OBJ_DIR)/$(PROJECT_DIR)/%.o, $(PROJECT_SRC))

PROG_NAME =	corewar

BASIC_LIB = $(LIB_DIR)/libmy.a
PROJECT_LIB = $(LIB_DIR)/lib$(PROG_NAME).a

FLAGS = -I$(INCLUDE_DIR) -g3

all: $(PROG_NAME)

$(BASIC_LIB): $(BASIC_OBJ)
	@mkdir -p $(LIB_DIR)
	ar rc $@ $^

$(PROJECT_LIB): $(BASIC_LIB) $(PROJECT_OBJ)
	ar rc $@ $(BASIC_OBJ) $(PROJECT_OBJ)

$(OBJ_DIR)/$(PROG_NAME).o: $(PROG_NAME).c
	gcc $(FLAGS) -c $(PROG_NAME).c -o $(OBJ_DIR)/$(PROG_NAME).o

$(PROG_NAME): $(PROJECT_LIB) $(OBJ_DIR)/$(PROG_NAME).o
	gcc -o $(PROG_NAME) $(OBJ_DIR)/$(PROG_NAME).o\
		-I$(INCLUDE_DIR) -L$(LIB_DIR) -l$(PROG_NAME) -g3

$(OBJ_DIR)/$(BASIC_DIR)/%.o: $(BASIC_DIR)/%.c
	@mkdir -p $(dir $@)
	gcc $(FLAGS) -c $< -o $@

$(OBJ_DIR)/$(PROJECT_DIR)/%.o: $(PROJECT_DIR)/%.c
	@mkdir -p $(dir $@)
	gcc $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(BASIC_LIB) $(PROJECT_LIB) $(PROG_NAME)

re: fclean all

codestyle:
	~/my_scripts/coding-style.sh . .
	cat coding-style-reports.log
	rm -f coding-style-reports.log

coding_style: fclean
	cd ../coding-style-checker/ \
	&& ./coding-style.sh ../B-CPE-200-MAR-2-1-corewar-kevin.huynh/ \
	&& cd ../B-CPE-200-MAR-2-1-corewar-kevin.huynh/ \
	&& clear \
	&& cd ../coding-style-checker/ \
	&& cat coding-style-reports.log

valgrind: re
	valgrind --leak-check=full --track-origins=yes --verbose \
	--show-reachable=yes --max-stackframe=500000 \
	--log-file=valgrind.log ./$(PROG_NAME)

unit_tests: re
	gcc -o unit_tests tests/*.c -I$(INCLUDE_DIR) -L$(LIB_DIR) -lproject \
	-g3 --coverage -lcriterion
	mv unit_tests tests/

push: fclean
	@(find . -type f -name "#.#" -delete -o -name "*~" -delete)
	@(git add .)
	@(git commit -m "[ADD] Prototypes for exec functions (instructions).")
	@(git push)

test: all
