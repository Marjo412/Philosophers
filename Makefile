# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marjorie <marjorie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/27 09:49:30 by mrosset           #+#    #+#              #
#    Updated: 2025/08/04 21:01:51 by marjorie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = includes

SRCS = src/main.c \
		src/utils.c \
		src/init.c \
		src/input.c \
		src/dinner.c \
		src/routine.c \
		src/monitor.c

OBJS = $(SRCS:.c=.o)

%.o: %.c
		$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
		@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re