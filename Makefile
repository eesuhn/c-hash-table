SRC = ft_std.c ft_string.c hash_table.c main.c prime.c
SRC_DIR = srcs/

OBJ_DIR = build/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

INC = -I includes/

NAME = ht

OUTPUT = $(OBJ_DIR)$(NAME)

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

all: $(OUTPUT)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OUTPUT): $(OBJ)
	$(CC) $(CFLAGS) $(INC) $(OBJ) -o $(OUTPUT)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(OUTPUT)

re: fclean all

.PHONY: all clean fclean re
