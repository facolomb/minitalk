SRCS	= ft_printf.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

AR		= ar rc

RM		= rm -f

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			$(MAKE) -C ./libft
			cp libft/libft.a $(NAME)
			${AR} ${NAME} ${OBJS}

clean:
			${MAKE} clean -C ./libft
			${RM} ${OBJS}

fclean:		clean
			${MAKE} fclean -C ./libft
			${RM} ${NAME}
			${RM} a.out

re :		fclean all

.PHONY:		all clean fclean re
