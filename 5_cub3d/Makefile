NAME = cub3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L./ -lmlx -framework OpenGL -framework AppKit 
LIBFT_DIR = ./libft
LIBFT = -L$(LIBFT_DIR) -lft
RM = rm -f
SRCS_PATH = ./srcs
OBJS_PATH = ./objs
GNL_PATH = ./get_next_line
INCS = -I./incs
SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME))
SRCS_NAME =	main.c\
		init.c\
		util.c\
		map.c\
		map_error.c\
		info_error.c\
		map_parsing.c\
		2d_image.c\
		ray.c\
		get_next_line.c\
		get_next_line_utils.c
OBJS_NAME = $(SRCS_NAME:.c=.o)
OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS_NAME))

all : $(NAME)

$(OBJS_PATH)/%.o : $(SRCS_PATH)/%.c
	$(CC) $(CFLAGS) $(INCS) -g -c $< -o $@

$(NAME) : $(OBJS)
	# make -C $(LIBFT_DIR)
	# make -C ..
	# mv ../libmlx.dylib ./
	$(CC) $(CFLAGS) $(LIBFT) $(INCS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

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
	$(CC) $(CFLAGS) $(LIBFT) $(INCS) -o $(NAME) $(OBJS) $(MLX_FLAGS) -fsanitize=address

re : fclean all

.PHONY : all clean fclean re
