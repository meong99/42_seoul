# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchae <mchae@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/09 16:16:57 by mchae             #+#    #+#              #
#    Updated: 2021/10/07 18:43:20 by mchae            ###   ########.fr        #
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
SRCS = \
       ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
       ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
       ft_memccpy.c ft_memcmp.c ft_memmove.c ft_bzero.c ft_memchr.c \
       ft_memcpy.c ft_memset.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
       ft_strchr_f.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
       ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
       ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c ft_free.c\
       ft_strjoin.c ft_strjoin_free.c ft_strtrim.c ft_split_f.c ft_split.c ft_itoa.c ft_strmapi.c \
       ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJS = $(patsubst %.c,%.o,$(SRCS))
BOBJS = $(patsubst %.c,%.o,$(BSRCS))

NO_COLOR = \033[1;36m
KILL_COLOR	= \033[0m

ifeq ($(DEBUG), 1)
	FLAGS = -g -Wall -Wextra -Werror
endif
ifeq ($(SANI), 1)
	FLAGS = -fsanitize=address -Wall -Wextra -Werror
endif

$(NAME) : $(OBJS)
	@ar rcs $@ $^
	@echo "$(NO_COLOR)libft making done$(KILL_COLOR)"
all : $(NAME)

%.o : %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean :
	@rm -f $(BOBJS) $(OBJS)
	@echo "$(NO_COLOR)libft cleaning done$(KILL_COLOR)"

fclean :
	@rm -f $(NAME)
	@rm -f $(BOBJS) $(OBJS)
	@echo "$(NO_COLOR)libft fcleaning done$(KILL_COLOR)"

re : fclean all

.PHONY: all clean fclean re
