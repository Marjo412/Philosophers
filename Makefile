
NAME = philosophers

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = includes

SRCS = main.c \
		utils.c \
		init_simulation.c \

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