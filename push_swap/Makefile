NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -Iinclude

SRCS		= src/main.c \
			  src/operations.c \
			  src/stack_utils.c \
			  src/parse.c \
			  src/sort.c \
			  src/sort_utils.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c include/push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
