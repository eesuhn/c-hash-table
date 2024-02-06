NAME = ft_ht

SRC_DIR = srcs/
SRC = $(wildcard $(SRC_DIR)*.c)

OBJ_DIR = build/
OBJ = $(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))

INC = -I includes/

CFLAGS =

DEBUG_W = -Wall -Wextra -Werror
DEBUG_F = -fsanitize=address

ifeq ($(D), 1)
	CFLAGS += $(DEBUG_W)
	CFLAGS += $(DEBUG_F)

else ifeq ($(D), 2)
	CFLAGS += $(DEBUG_W)

else ifeq ($(D), 3)
	CFLAGS += $(DEBUG_F)

endif

OUTPUT_DIR = ./
OUTPUT = $(OUTPUT_DIR)$(NAME)

all: $(OUTPUT)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	cc $(CFLAGS) $(INC) -c $< -o $@

$(OUTPUT): $(OBJ_DIR) $(OBJ)
	cc $(CFLAGS) $(INC) $(OBJ) -o $(OUTPUT)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(OUTPUT)

re: fclean all

.PHONY: clean fclean re
