SRC	=	src/my_ftp.c	\
		src/check.c	\
		src/cmd_noop.c	\
		src/disconnect.c	\
		src/location.c	\
		src/protocol.c	\
		src/cmd_help.c	\
		src/connected.c	\
		src/main.c	\
		src/cmd_quit.c	\
		src/user.c

OBJ	=	${SRC:.c=.o}

NAME	=	myftp

all:	${NAME}

${NAME}:	${OBJ}
	gcc -o ${NAME} ${OBJ}

clean:
	find -name "*~" -delete
	find -name "*#" -delete
	find -name "*.o" -delete

fclean:	clean
	find -name ${NAME} -delete

re: fclean all

.PHONY:	all clean fclean re
