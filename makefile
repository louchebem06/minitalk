NAME	= minitalk.a
SRCS	= src/ft_atoi.c \
			src/ft_calloc.c \
			src/ft_isdigit.c \
			src/ft_iswhitespace.c \
			src/ft_memset.c \
			src/ft_putchar_fd.c \
			src/ft_putstr_fd.c \
			src/ft_strjoin.c \
			src/ft_strlen.c \
			src/ft_itoa.c \
			src/ft_strdup.c  
OBJS	= ${SRCS:.c=.o}

CC		= gcc
CFLAGS  = -Wall -Wextra -Werror
RM		= rm -f

$(NAME):	${OBJS}
			ar -rcs ${NAME} ${OBJS}
			${CC} ${CFLAGS} src/server.c ${NAME} -o server
			${CC} ${CFLAGS} src/client.c ${NAME} -o client

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

bonus:		${NAME}

clean:
			${RM} ${OBJS} ${OBJSBONUS}

fclean:		clean
			${RM} ${NAME}
			${RM} server
			${RM} client

re:			fclean all

.PHONY: $(NAME) all clean fclean re bonus