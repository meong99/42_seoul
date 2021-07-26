# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/08 18:33:31 by mchae             #+#    #+#              #
#    Updated: 2021/07/23 17:58:28 by mchae            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_PATH = libft
INCLUDES = -I includes
OBJS_PATH = objs
SRCS_PATH = srcs

SRCS = \
	main.c\
	error_check.c\
	init_all.c\
	thread_philo.c\
	free_all.c\
	util.c

OBJS_NAME = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS_NAME))

ifeq ($(DEBUG), 1)
	CFLAGS = -g -Wall -Wextra -Werror
endif
ifeq ($(SANI), 1)
	CFLAGS = -g -fsanitize=address -Wall -Wextra -Werror
endif

$(OBJS_PATH)/%.o : $(SRCS_PATH)/%.c
	mkdir -p $(OBJS_PATH)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME) : $(OBJS)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) -L$(LIBFT_PATH) -lft -o $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -rf $(OBJS_PATH)
	make -C $(LIBFT_PATH) fclean
fclean : clean
	rm -f $(NAME)
re : fclean all

.PHONY: all clean fclean re bonus
