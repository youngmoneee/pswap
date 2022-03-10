# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 00:30:38 by youngpar          #+#    #+#              #
#    Updated: 2022/03/08 03:53:19 by youngpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
#CFLAGS	= ''-Wall -Wextra -Werror

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
BNSFILE	= main_bonus.c \
		  deque_front_bonus.c \
		  deque_back_bonus.c \
		  parse_bonus.c \
		  util_bonus.c \
		  algo_bonus.c \
		  swap_bonus.c \
		  swap2_bonus.c

SRCS	= $(addprefix $(SRCDIR)/, $(SRCFILE))
BSRCS	= $(addprefix $(BNSDIR)/, $(BNSFILE))

OBJS	= $(SRCS:.c=.o)
BOBJS	= $(BSRCS:.c=.o)

.c.o	:
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

all		: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I $(INCLUDE) -o $(NAME)

bonus	: $(BOBJS)
	$(CC) $(CFLAGS) $(BOBJS) -I $(INCLUDE) -o $(NAME)

clean	:
	@rm -rf $(OBJS) $(BOBJS)

fclean	: clean
	@rm -rf $(NAME)

re		: fclean all

.PHONY	: all $(NAME) bonus clean fclean re $(FT)
