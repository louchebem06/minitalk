# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/06 04:42:36 by bledda            #+#    #+#              #
#    Updated: 2021/06/06 04:43:14 by bledda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= minitalk

FOLDER				= src/

SRCS_CLIENT			= ft_atoi.c \
					ft_putchar_fd.c \
					ft_putstr_fd.c \
					ft_strjoin.c \
					ft_iswhitespace.c \
					ft_isdigit.c \
					ft_strlen.c \
					ft_calloc.c \
					ft_memset.c \
					client.c

SRCS_SERVER			= ft_putchar_fd.c \
					ft_putstr_fd.c \
					ft_itoa.c \
					ft_strdup.c \
					ft_strlen.c \
					ft_calloc.c \
					ft_memset.c \
					server.c

SRCS_CLIENT_BONUS	= ft_atoi.c \
					ft_putchar_fd.c \
					ft_putstr_fd.c \
					ft_strjoin.c \
					ft_iswhitespace.c \
					ft_isdigit.c \
					ft_strlen.c \
					ft_calloc.c \
					ft_memset.c \
					client_bonus.c

SRCS_SERVER_BONUS	= ft_putchar_fd.c \
					ft_putstr_fd.c \
					ft_itoa.c \
					ft_strdup.c \
					ft_strlen.c \
					ft_calloc.c \
					ft_memset.c \
					server_bonus.c

SRC_CLIENT			= $(addprefix ${FOLDER},${SRCS_CLIENT})
SRC_SERVER			= $(addprefix ${FOLDER},${SRCS_SERVER})
SRC_CLIENT_BONUS	= $(addprefix ${FOLDER},${SRCS_CLIENT_BONUS})
SRC_SERVER_BONUS	= $(addprefix ${FOLDER},${SRCS_SERVER_BONUS})

OBJS_CLIENT			= ${SRC_CLIENT:.c=.o}
OBJS_SERVER			= ${SRC_SERVER:.c=.o}
OBJS_CLIENT_BONUS	= ${SRC_CLIENT_BONUS:.c=.o}
OBJS_SERVER_BONUS	= ${SRC_SERVER_BONUS:.c=.o}

CC					= gcc
CFLAGS  			= -Wall -Wextra -Werror
RM					= rm -f

$(NAME)				:	server client

server				:	${OBJS_SERVER}
						${CC} ${CFLAGS} ${OBJS_SERVER} -o server

client				:	${OBJS_CLIENT}
						${CC} ${CFLAGS} ${OBJS_CLIENT} -o client

server_bonus		:	${OBJS_SERVER_BONUS}
						${CC} ${CFLAGS} ${OBJS_SERVER_BONUS} -o server

client_bonus		:	${OBJS_CLIENT_BONUS}
						${CC} ${CFLAGS} ${OBJS_CLIENT_BONUS} -o client

bonus				:	server_bonus client_bonus

all					: 	${NAME}

clean				:
						${RM} ${OBJS_SERVER} ${OBJS_CLIENT}

fclean				:	clean
						${RM} server
						${RM} client

re					:	fclean all

.PHONY				:	$(NAME)	all clean fclean re bonus client_bonus server_bonus