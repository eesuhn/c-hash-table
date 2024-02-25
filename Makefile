NAME := libft_ht.a

SRCS := $(wildcard srcs/*.c)

OBJS := $(addprefix build/, $(notdir $(SRCS:.c=.o)))

FLAGS := -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

build/%.o: srcs/%.c
	cc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
