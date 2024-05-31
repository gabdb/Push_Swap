NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = 	algo.c\
		algo2.c\
		fifty_hack.c\
		help_algo.c\
		help_chosen_index.c\
		help_operations.c\
		input_validity.c\
		main.c\
		make_nodes.c\
		operations.c\
		split.c\
		utils.c\
		utils2.c\

OBJ = $(SRC:.c=.o)

# Default target
all: $(NAME)

# Link the program
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

# Compile the source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Build the libft library
$(LIBFT):
	make -C libft/

# Clean objects
clean:
	rm -f $(OBJ)

# Clean everything
fclean: clean
	rm -f $(NAME)

# Rebuild the project
re: fclean all

# Declare phony targets
.PHONY: all clean fclean re
