# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svereten <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 12:00:15 by svereten          #+#    #+#              #
#    Updated: 2024/04/22 12:44:08 by svereten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

INCLUDES = -I ./includes/

SRC_DIR = ./src/

SRC_FILES = ft_printf.c

OBJ_FILES = ${SRC_FILES:.c=.o}

SRCS = ${addprefix ${SRC_DIR}, ${SRC_FILES}}

OBJS = ${addprefix ${SRC_DIR}, ${OBJ_FILES}}

LIBFT = libft.a

LIBFT_DIR = ./libft/

LIBFT_AR = ${addprefix ${LIBFT_DIR}, ${LIBFT}}

AR = ar

RM = rm -rf

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT_AR}
	${AR} rsc ${NAME} ${OBJS}

${LIBFT_AR}:
	${MAKE} ${LIBFT} -C ${LIBFT_DIR}
	cp ${LIBFT_AR} ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c ${INCLUDES} $< -o $@

clean:
	${RM} ${OBJS}
	${MAKE} clean -C ${LIBFT_DIR}

fclean: clean
	${RM} ${NAME}
	${MAKE} fclean -C ${LIBFT_DIR}

re: fclean all

.PHONY: all clean fclean re
