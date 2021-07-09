# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sohelee <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/11 15:27:51 by sohelee           #+#    #+#              #
#    Updated: 2021/05/11 16:57:39 by sohelee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libasm.a

SRCS	= ft_strlen.s \
		  ft_strcpy.s \
		  ft_strcmp.s \
		  ft_strdup.s \
		  ft_read.s \
		  ft_write.s

OBJS	= $(SRCS:.s=.o)

TEST	= test

%.o		: %.s
		nasm -f macho64 $<

all		: $(NAME)

$(NAME)	: $(OBJS)
		ar rc $(NAME) $(OBJS)

clean	:
		rm -rf $(OBJS)

fclean	: clean
		rm -rf $(NAME) $(TEST) $(NAME)

re		: fclean all

test	: re
		gcc main.c -o test -L. -lasm
