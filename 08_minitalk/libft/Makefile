# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/09 16:16:57 by mchae             #+#    #+#              #
#    Updated: 2021/06/14 17:05:00 by mchae            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
HEADER = ./
BSRCS = ft_lstnew.c \
         ft_lstadd_front.c \
         ft_lstsize.c \
         ft_lstlast.c \
         ft_lstadd_back.c \
         ft_lstdelone.c \
         ft_lstclear.c \
         ft_lstiter.c \
         ft_lstmap.c
SRCS = ft_memccpy.c ft_memcmp.c ft_memmove.c ft_bzero.c ft_memchr.c \
       ft_memcpy.c ft_memset.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
       ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
       ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
       ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c \
       ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
       ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
       ft_malloc.c ft_free.c
OBJS = $(patsubst %.c,%.o,$(SRCS))
BOBJS = $(patsubst %.c,%.o,$(BSRCS))

ifeq ($(DEBUG), true)
	CDEBUG = -g
endif
ifeq ($(SANI), true)
	CDEBUG = -g -fsanitize=address
endif
all : $(NAME)
%.o : %.c
	$(CC) $(FLAGS) $(CDEBUG) -c $< -o $@
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
