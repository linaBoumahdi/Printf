# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lboumahd <lboumahd@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/27 19:51:07 by lboumahd          #+#    #+#              #
#    Updated: 2024/04/27 19:55:48 by lboumahd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = libftprintf.a

SRCS =  ft_prinft.c 		\
		ft_printf_utils.c 	\

OBJS = $(SRCS:.c=.o)

CFLAGS  =  -Wall -Wextra -Werror

all = $(NAME)

$(NAME) = $(OBJS)
	@ar rc $(NAME) $(OBJS)

%.o:	%.c 
	gcc ${FLAGS} -I . -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re