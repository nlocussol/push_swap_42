# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 17:13:34 by nlocusso          #+#    #+#              #
#    Updated: 2022/11/05 10:08:57 by nlocusso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= main.c special_sort.c utils.c initialized_free.c pars_argv.c sort_algo.c r_movement.c other_movement.c
BSRCS		= checker_bonus/main_bonus.c pars_argv.c checker_bonus/check_move.c checker_bonus/r_movement_bonus.c checker_bonus/other_movement_bonus.c initialized_free.c
OBJS		= ${SRCS:.c=.o}
BOBJS		= ${BSRCS:.c=.o}
NAME		= push_swap
BONUS		= checker
CC			= gcc -g
CFLAGS		= -Wall -Wextra -Werror

all :        ${NAME}

.c.o :		${OBJS}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
	
${NAME}:	${OBJS}
			make -C libft
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} libft/libft.a libft/ft_printf/libftprintf.a

bonus:		${BOBJS}
			make -C libft
			${CC} ${CFLAGS} -o ${BONUS} ${BOBJS} libft/libft.a libft/ft_printf/libftprintf.a

clean :
			rm -f ${OBJS} ${BOBJS}
			make -C libft clean

fclean :	clean
			rm -f ${NAME} 
			make -C libft fclean

re :
			make fclean
			make all

.PHONY : all clean fclean re bonus
