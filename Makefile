NAME					=		minishell

CFLAGS					=		-O3 -Wall -Wextra -Werror  -I ./includes
CFLAGS_DEV				=		-g -O3 -I ./includes

LIBFT					=		./libft
LIBFT_A					=		$(LIBFT)/libft.a

LINKER					=		-lreadline -L${LIBFT} -lft

CC						=		cc

SRC_DIR					=		./src/
SRC_FILES				=		$(SRC_DIR)/main.c

OBJ_DIR					=		obj
OBJ_FILES				=		$(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS_DEV) -c $< -o $@

$(LIBFT_A):	
	${MAKE} -C ${LIBFT}

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT_A)
	$(CC) $(CFLAGS_DEV) $(OBJ_FILES) $(LINKER) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	${MAKE} -C ${LIBFT} clean

fclean: clean
	rm -rf $(NAME)
	${MAKE} -C ${LIBFT} fclean

re: fclean all

.PHONY: all clean fclean re
