NAME = cub3D

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L./ -lmlx -framework OpenGL -framework AppKit

SRCS_PATH = ./srcs
OBJS_PATH = ./objs
GNL_PATH = ./get_next_line
LIBFT_PATH = ./libft
MLX_PATH = ./mlxs
INCS_PATH = ./includes

LIBFT = -L$(LIBFT_PATH) -lft
INCS = -I$(INCS_PATH)

SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME))
OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS_NAME))

SRCS_NAME =	main.c\
		init.c\
		util.c\
		map.c\
		map_error.c\
		info_error.c\
		map_parsing.c\
		ray.c\
		ray_util.c\
		ray_init.c\
		image.c\
		player.c\
		player_move.c\
		malloc_free.c\
		get_next_line.c\
		get_next_line_utils.c
OBJS_NAME = $(SRCS_NAME:.c=.o)

RM = rm -f

ifeq ($(DEBUG), true)
	CDEBUG = -g
endif

ifeq ($(SANITIZE), true)
	FSANITIZE = -g -fsanitize=address
endif

all : $(NAME)

$(OBJS_PATH)/%.o : $(SRCS_PATH)/%.c
	@mkdir -p $(OBJS_PATH)
	@$(CC) $(CFLAGS) $(CDEBUG) $(FSANITIZE) $(INCS) -c $< -o $@

make_path :
	make -C $(LIBFT_PATH)
	make -C $(MLX_PATH)
	mv $(MLX_PATH)/libmlx.dylib ./

$(NAME) : make_path $(OBJS)
	$(CC) $(CFLAGS) $(LIBFT) $(INCS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

clean :
	$(RM) $(OBJS)
	make -C $(LIBFT_PATH) fclean
	$(RM) libmlx.dylib
	make -C $(MLX_PATH) clean

fclean : clean
	$(RM) $(NAME)

debug : make_path $(OBJS)
	$(CC) $(CFLAGS) $(LIBFT) $(CDEBUG) $(FSANITIZE) $(INCS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

re : fclean all

.PHONY : all clean fclean re
