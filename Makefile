SRCS	= main.c parsing.c utils.c path.c ft_splitpath.c

OBJS	= ${SRCS:.c=.o}

DEPS	= ${SRCS:.c=.d}

NAME	= pipex

CC	= gcc

CFLAGS	= -MMD -Wall -Wextra -Werror -g3


$(NAME):	${OBJS}
		make -C ./libft
		$(CC) $(CFLAGS) ${OBJS} ./libft/libft.a -o ${NAME}

all:	${NAME}

clean:
		rm -f ${OBJS} ${DEPS}

fclean:	
		rm -f ${NAME}
		rm -f ${OBJS}
		rm -f ${DEPS}
		make -C ./libft fclean

re:		fclean
		make all

ac :	all
		make clean

do : 	all
		./${NAME}

.PHONY: all clean fclean re ac do

-include ${DEPS}
