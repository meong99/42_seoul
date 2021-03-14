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

SRCS_NAME =	\
		ft_get_next_line_utils.c\
		ft_get_next_line.c\
		ft_image.c\
		ft_info_error.c\
		ft_init.c\
		ft_key_set.c\
		ft_main.c\
		ft_malloc_free.c\
		ft_map_error.c\
		ft_map_parsing.c\
		ft_map.c\
		ft_player_move.c\
		ft_player.c\
		ft_ray_init.c\
		ft_ray_util.c\
		ft_ray.c\
		ft_sort.c\
		ft_sprite.c\
		ft_texture.c\
		ft_util.c
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
