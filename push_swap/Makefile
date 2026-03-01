NAME = push_swap

CC = cc

CFLAGS = -Werror -Wall -Wextra

RM = rm -rf

LIBFT = libft/libft.a

PRINTF = ft_printf/libftprintf.a

SRCS = 	\
src/sorting/push_swap.c\
src/sorting/sort_utils.c\
src/stack/get_stack.c\
src/stack/push_operation.c\
src/stack/rotate_operation.c\
src/stack/stack_utils.c\
src/stack/str_arr.c

$(NAME) :
	make -C libft
	make -C ft_printf
	cc $(CFLAGS) $(SRCS) $(LIBFT) $(PRINTF) -o $(NAME)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft
	make fclean -C ft_printf

clean :
	$(RM) $(NAME)
	make clean -C libft
	make clean -C ft_printf

re : fclean all