SRCS_SRV	= server.c

SRCS_CLI	= client.c

NAME_SRV	= server

NAME_CLI	= client

LIB		= ./printf

RM		= rm -f

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

all:		makelib exsrv excli

makelib:
			$(MAKE) -C ./printf
exsrv:
			${CC} ${SRCS_SRV} ${LIB} ${CFLAGS} -o ${NAME_SRV}
excli:
			${CC} ${SRCS_CLI} ${LIB} ${CFLAGS} -o ${NAME_CLI}
clean:
			${MAKE} clean -C ./printf

fclean:		clean
			${MAKE} fclean -C ./printf
			${RM} ${NAME_SRV} ${NAME_CLI}

re :		fclean all

.PHONY:		all clean fclean re
