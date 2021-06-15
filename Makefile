# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/06 04:42:36 by bledda            #+#    #+#              #
#    Updated: 2021/06/15 18:04:42 by bledda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= minitalk

FOLDER				= src/

HEADER_FILE 		= header/minitalk.h
HEADER_FILE_BONUS 	= header/minitalk_bonus.h
					
SRCS_COMMUN         = ft_memset.c \
					ft_strlen.c \
					ft_calloc.c \
					ft_putchar_fd.c \
					ft_putstr_fd.c \
					ft_itoa.c \
					ft_strdup.c \
					ft_atoi.c \
					ft_strjoin.c \
					ft_iswhitespace.c \
					ft_isdigit.c 

SRCS_CLIENT_BONUS	= client_bonus.c

SRCS_SERVER_BONUS	= server_bonus.c

SRCS_CLIENT			= client.c

SRCS_SERVER			= server.c

SRC_COMMUN			= $(addprefix ${FOLDER},${SRCS_COMMUN})
SRC_CLIENT			= $(addprefix ${FOLDER},${SRCS_CLIENT})
SRC_SERVER			= $(addprefix ${FOLDER},${SRCS_SERVER})
SRC_CLIENT_BONUS	= $(addprefix ${FOLDER},${SRCS_CLIENT_BONUS})
SRC_SERVER_BONUS	= $(addprefix ${FOLDER},${SRCS_SERVER_BONUS})

OBJS_COMMUN			= ${SRC_COMMUN:.c=.o}
OBJS_CLIENT			= ${SRC_CLIENT:.c=.o}
OBJS_SERVER			= ${SRC_SERVER:.c=.o}
OBJS_CLIENT_BONUS	= ${SRC_CLIENT_BONUS:.c=.o}
OBJS_SERVER_BONUS	= ${SRC_SERVER_BONUS:.c=.o}

CC					= gcc
CFLAGS  			= -Wall -Wextra -Werror
RM					= rm -f

ifdef WITH_BONUS
OBJ_CLIENT 			= $(OBJS_CLIENT_BONUS) $(OBJS_COMMUN)
OBJ_SERVER 			= $(OBJS_SERVER_BONUS) $(OBJS_COMMUN)
HEADER 				= $(HEADER_FILE) $(HEADER_FILE_BONUS)
else
OBJ_CLIENT 			= $(OBJS_CLIENT) $(OBJS_COMMUN)
OBJ_SERVER 			= $(OBJS_SERVER) $(OBJS_COMMUN)
HEADER 				= $(HEADER_FILE)
endif

$(NAME):	server client

server:		${OBJ_SERVER}
			$(CC) $(CFLAGS) ${OBJ_SERVER} -o server

client: 	${OBJ_CLIENT}
			$(CC) $(CFLAGS) ${OBJ_CLIENT} -o client

all:		${NAME}

%.o: %.c	$(HEADER)
			$(CC) -c $(CFLAGS) -o $@ $<

re: 		fclean all

clean:
			${RM} $(OBJS_CLIENT_BONUS) $(OBJS_SERVER_BONUS) $(OBJS_CLIENT) $(OBJS_SERVER) $(OBJS_COMMUN)

fclean:		clean
			${RM} server client

bonus: 		
			$(MAKE) WITH_BONUS=1

.PHONY: 	$(NAME) all clean fclean re bonus
