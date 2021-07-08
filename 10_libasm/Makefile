# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/08 16:36:08 by mchae             #+#    #+#              #
#    Updated: 2021/07/08 17:40:49 by mchae            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a
NASM = nasm
NASMFLAGS = -f macho64

OBJS_PATH = objs
SRCS_PATH = srcs

SRCS = \
	ft_strlen.s\
	ft_strcpy.s\
	ft_strcmp.s\
	ft_write.s\
	ft_read.s\
	ft_strdup.s

OBJS_NAME = $(SRCS:.s=.o)
OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS_NAME))

ifeq ($(DEBUG), true)
	NASMFLAGS = -f macho64 -g
endif
ifeq ($(SANI), true)
	NASMFLAGS = -f macho64 -g -fsanitize=address
endif

$(OBJS_PATH)/%.o : $(SRCS_PATH)/%.s
	mkdir -p $(OBJS_PATH)
	$(NASM) $(NASMFLAGS) $< -o $@

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -rf $(OBJS)
fclean : clean
	rm -rf $(NAME) $(OBJS_PATH)
re : fclean all

.PHONY: all clean fclean re bonus
