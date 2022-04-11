# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 00:30:38 by youngpar          #+#    #+#              #
#    Updated: 2022/04/11 18:21:32 by youngpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

NAME	= push_swap

INCLUDE	= ./include

SRCDIR	= srcs
BNSDIR	= bonus

SRCFILE	= main.c \
		  deque_front.c \
		  deque_back.c \
		  parse.c \
		  util.c \
		  algo.c \
		  swap.c \
		  swap2.c

SRCS	= $(addprefix $(SRCDIR)/, $(SRCFILE))
OBJS	= $(SRCS:.c=.o)

.c.o	:
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

all		: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I $(INCLUDE) -o $(NAME)

clean	:
	@rm -rf $(OBJS)

fclean	: clean
	@rm -rf $(NAME)

re		: fclean all

.PHONY	: all $(NAME) clean fclean re
