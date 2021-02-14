NAME = cub3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L./mlxs/ -lmlx -framework OpenGL -framework AppKit 
LIBFT_DIR = ./libft
LIBFT = -L$(LIBFT_DIR) -lft
GNL = -D BUFFER_SIZE=10
RM = rm -f
SRCS_PATH = ./srcs/
OBJS_PATH = ./objs/
SRCS =	main.c\
		init.c\
		util.c\
		map.c\
		map_error.c\
		info_error.c\
		map_parsing.c\
		2d_image.c\
		ray.c\
		./get_next_line/get_next_line.c\
		./get_next_line/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -g $(GNL) -c $< -o $@

$(NAME) : $(OBJS)
	# make -C $(LIBFT_DIR)
	# make -C ..
	# mv ../libmlx.dylib ./
	$(CC) $(CFLAGS) $(LIBFT) -o $(NAME) $(OBJS) $(MLX_FLAGS)

clean :
	$(RM) $(OBJS)
	# make -C $(LIBFT_DIR) fclean
	# $(RM) libmlx.dylib
	# make -C .. clean

fclean : clean
	$(RM) $(NAME)

leak : $(OBJS)
	# make -C $(LIBFT_DIR)
	# make -C ..
	$(CC) $(CFLAGS) $(LIBFT) -o $(NAME) $(OBJS) $(MLX_FLAGS) -fsanitize=address

re : fclean all

.PHONY : all clean fclean re
