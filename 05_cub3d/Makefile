NAME = cub3D
B_NAME = $(NAME)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L./ -lmlx -framework OpenGL -framework AppKit

INCS_PATH = ./includes
GNL_PATH = ./get_next_line
LIBFT_PATH = ./libft
OBJS_PATH = ./objs
LIBFT = -L$(LIBFT_PATH) -lft
INCS = -I$(INCS_PATH) -I$(MLX_PATH)


RM = rm -rf

SRCS_NAME =	\
		get_next_line_utils.c\
		get_next_line.c\
		image.c\
		info_error.c\
		init.c\
		key_set.c\
		main.c\
		malloc_free.c\
		map_error.c\
		parsing_info.c\
		parsing_map.c\
		player.c\
		ray_util.c\
		raycasting.c\
		save.c\
		sort.c\
		sprite_cast.c\
		sprite.c\
		texture.c\
		util.c

BSRCS_NAME = \
		bonus_more_sprite_bonus.c\
		bonus.c\
		get_next_line_utils_bonus.c\
		get_next_line_bonus.c\
		image_bonus.c\
		info_error_bonus.c\
		init_bonus.c\
		key_set_bonus.c\
		main_bonus.c\
		malloc_free_bonus.c\
		map_error_bonus.c\
		parsing_info_bonus.c\
		parsing_map_bonus.c\
		player_bonus.c\
		ray_util_bonus.c\
		raycasting_bonus.c\
		save_bonus.c\
		sort_bonus.c\
		sprite_cast_bonus.c\
		sprite_bonus.c\
		texture_bonus.c\
		util_bonus.c

ifeq ($(DEBUG), true)
	CDEBUG = -g
endif
ifeq ($(SANITIZE), true)
	FSANITIZE = -g -fsanitize=address
endif
ifeq ($(OPENGL), true)
	MLX_PATH = ./opengl_mlx
else
	MLX_PATH = ./mms_mlx
	MV_MMS_NAME = mv $(MLX_PATH)/libmlx.dylib ./
	RM_MMS_NAME = $(RM) libmlx.dylib
endif
ifeq ($(WITH_BONUS), true)
	SRCS_PATH = ./bonus_srcs
	OBJS_NAME = $(BSRCS_NAME:.c=.o)
	OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS_NAME))
else
	SRCS_PATH = ./srcs
	OBJS_NAME = $(SRCS_NAME:.c=.o)
	OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS_NAME))
endif


$(OBJS_PATH)/%.o : $(SRCS_PATH)/%.c
	@mkdir -p $(OBJS_PATH)
	@$(CC) $(CFLAGS) $(CDEBUG) $(FSANITIZE) $(INCS) -c $< -o $@

all : $(NAME)

bonus :
	make WITH_BONUS=true all

$(NAME) : $(OBJS)
	make -C $(LIBFT_PATH)
	make -C $(MLX_PATH)
	$(MV_MMS_NAME)
	$(CC) $(CFLAGS) $(LIBFT) $(CDEBUG) $(FSANITIZE) $(INCS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

clean :
	make -C $(LIBFT_PATH) fclean
	make -C $(MLX_PATH) clean

fclean : clean
	$(RM) $(OBJS_PATH) screenshot.bmp $(NAME)
	$(RM_MMS_NAME)

re : fclean all

bre : fclean bonus

.PHONY : all clean fclean re bonus
