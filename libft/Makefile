# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchae <mchae@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/09 16:16:57 by mchae             #+#    #+#              #
#    Updated: 2020/10/09 18:08:25 by mchae            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAG = -Wall -Wextra -Werror
SRCS = ${shell echo *.c}
OBJS = ${SRCS:.c=.o}
HEADER = ./
$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)
%.o: %.c
	gcc $(FLAG) -c $< -o $@
all : $(NAME)
clean :
	/bin/rm -f $(OBJS)
fclean : clean
	/bin/rm -f $(NAME)
re : fclean all
.PHONY: all clean fclean re
