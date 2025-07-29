# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marjorie <marjorie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/27 09:49:30 by mrosset           #+#    #+#              #
#    Updated: 2025/07/28 22:10:32 by marjorie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = includes

SRCS = main.c \
		utils.c \
		init.c \
		input.c \
		dinner.c \
		routine.c \

OBJS = $(SRCS:.c=.o)

%.o: %.c
		$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)

clean:
		rm -rf $(OBJS)
		make clean

fclean: clean
		rm -rf $(NAME)
		make fclean

re: fclean all

.PHONY: all clean fclean re