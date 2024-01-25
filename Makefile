SRCS = push_swap.c\
		stack_init.c\
		stack_create_destroy.c\
		stack_control.c\
		operations.c\
		combined_operations.c\
		priority_controls.c\
		push_swap_utils.c\
		utilities.c\
		main.c
CFLAGS = -Wall -Wextra -Werror -g3 
PROGRAM = push_swap
LIBFT_DIR = libft
CC = cc

all: ${NAME}

${NAME}: ${SRCS}
	@make -C $(LIBFT_DIR)
	${CC} ${CFLAGS} ${SRCS} -I. -o ${PROGRAM} -L$(LIBFT_DIR) -lft

clean:
	@make -C $(LIBFT_DIR) clean

fclean:
	@make -C $(LIBFT_DIR) fclean
	rm -rf ${PROGRAM}

re:	fclean all

.PHONY:	all clean fclean re
