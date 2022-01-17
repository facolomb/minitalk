SRCS_SRV	= server.c

SRCS_CLI	= client.c

NAME_SRV	= server

NAME_CLI	= client

LIB_PATH	= ./printf

LIB		= ./printf/libftprintf.a

RM		= rm -f

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

all:		makelib exsrv excli

makelib:
			$(MAKE) -C ${LIB_PATH}
exsrv:
			${CC} ${SRCS_SRV} ${LIB} ${CFLAGS} -o ${NAME_SRV}
excli:
			${CC} ${SRCS_CLI} ${LIB} ${CFLAGS} -o ${NAME_CLI}
clean:
			${MAKE} clean -C ${LIB_PATH}

fclean:		clean
			${MAKE} fclean -C ${LIB_PATH}
			${RM} ${NAME_SRV} ${NAME_CLI}

re :		fclean all

.PHONY:		all clean fclean re makelib excli exsrv
