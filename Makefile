NAME  = libftprintf.a

SRCS =  ft_printf.c 		\
		ft_printf_utils.c 	\

OBJS = $(SRCS:.c=.o)

CFLAGS  =  -Wall -Wextra -Werror



$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)

%.o:	%.c 
	gcc ${FLAGS} -I . -c $< -o $@

all : $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re