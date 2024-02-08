NAME = libft_ht.a

SRC_DIR = srcs/
SRC = $(wildcard $(SRC_DIR)*.c)

OBJ_DIR = build/
OBJ = $(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))

INC = -I includes/

CFLAGS = -Wall -Wextra -Werror

OUTPUT_DIR = ./
OUTPUT = $(OUTPUT_DIR)$(NAME)

all: $(OUTPUT)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	cc $(CFLAGS) $(INC) -c $< -o $@

$(OUTPUT): $(OBJ_DIR) $(OBJ)
	ar rcs $(OUTPUT) $(OBJ)
	ranlib $(OUTPUT)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(OUTPUT)

re: fclean all

.PHONY: all clean fclean re
