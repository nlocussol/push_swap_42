# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 17:13:34 by nlocusso          #+#    #+#              #
#    Updated: 2022/11/02 23:15:12 by nlocusso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= main.c pars_argv.c sort_algo.c r_movement.c other_movement.c
OBJS		= ${SRCS:.c=.o}
NAME		= push_swap
CC			= gcc -g
CFLAGS		= -Wall -Wextra -Werror

all :        ${NAME}

.c.o :		${OBJS}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
	
${NAME}:	${OBJS} libft.a 
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} libft/libft.a libft/ft_printf/libftprintf.a

clean :
			rm -f ${OBJS}
			make -C libft clean

libft.a :
	make -C libft

fclean :	clean
			rm -f ${NAME} 
			make -C libft fclean

re :        fclean all

.PHONY : all clean fclean re bonus
