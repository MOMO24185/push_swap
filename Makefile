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
CFLAGS = -Wall -Wextra -Werror
INCLUDES = ./
NAME = push_swap.a
PROGRAM = push_swap
CC = cc
OBJECTS = ${SRCS:.c=.o}
AR = ar
ARFLAGS = -rcs

${NAME}: ${SRCS}
	echo "Compiling LIBFT archive"
	make -C ./libft fclean all clean
	mv ./libft/libft.a ${NAME}
	${CC} ${CFLAGS} ${SRCS} ${NAME} -I ${INCLUDES} -o ${PROGRAM}

all: ${NAME}

clean:
	echo "rm -f ${OBJECTS} ${NAME}"
	rm -f ${OBJECTS} ${NAME}

fclean:	clean
	echo "rm -f ${PROGRAM}"
	rm -f ${PROGRAM}

re:	fclean all

.PHONY:	all clean fclean re
