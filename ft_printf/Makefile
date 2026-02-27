NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

SRCS =  \
ft_print_char.c \
ft_print_dec.c \
ft_print_hex_low.c \
ft_print_hex_uppr.c \
ft_print_percnt.c \
ft_print_str.c \
ft_print_un_dec.c \
ft_print_ptr.c \
ft_printf.c \
ft_strchr.c \
ft_strlen.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
