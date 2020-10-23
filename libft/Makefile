# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchae <mchae@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/09 16:16:57 by mchae             #+#    #+#              #
#    Updated: 2020/10/23 18:57:30 by mchae            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
HEADER = ./
BSRCS = $(wildcard *lst*.c)
SRCS = $(filter-out $(BSRCS), $(wildcard ft_*.c))
OBJS = $(patsubst %.c,%.o,$(SRCS))
BOBJS = $(patsubst %.c,%.o,$(BSRCS))
all : $(NAME)
%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@
$(NAME) : $(OBJS)
	ar rcs $@ $^
bonus: $(BOBJS)
	ar rcs $(NAME) $^
clean :
	rm -f $(BOBJS) $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all
.PHONY: all clean fclean re bonus
