NAME = cub3D

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L./ -lmlx -framework OpenGL -framework AppKit

SRCS_PATH = ./srcs
INCS_PATH = ./includes
OBJS_PATH = ./objs
BSRCS_PATH = ./bsrcs
BOBJS_PATH = ./bobjs
GNL_PATH = ./get_next_line
LIBFT_PATH = ./libft
MLX_PATH = ./mms_mlx

LIBFT = -L$(LIBFT_PATH) -lft
INCS = -I$(INCS_PATH)

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
		bonus.c\
		get_next_line_utils.c\
		get_next_line.c\
		image.c\
		info_error.c\
		init.c\
		key_set.c\
		main.c\
		malloc_free.c\
		map_error.c\
		more_sprite.c\
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

ifeq ($(DEBUG), true)
	CDEBUG = -g
endif
ifeq ($(SANITIZE), true)
	FSANITIZE = -g -fsanitize=address
endif
ifeq ($(OPENGL), true)
	MLX_PATH = ./opengl_mlx
endif
ifeq ($(OPENGL), false)
	MV_MMS_NAME = mv $(MLX_PATH)/libmlx.dylib ./
endif
ifeq ($(OPENGL), false)
	RM_MMS_NAME = $(RM) libmlx.dylib
endif

SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME))
BSRCS = $(addprefix $(BSRCS_PATH)/, $(BSRCS_NAME))
OBJS_NAME = $(SRCS_NAME:.c=.o)
OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS_NAME))
BOBJS_NAME = $(BSRCS_NAME:.c=.o)
BOBJS = $(addprefix $(BOBJS_PATH)/, $(BOBJS_NAME))

$(OBJS_PATH)/%.o : $(SRCS_PATH)/%.c
	@mkdir -p $(OBJS_PATH)
	@$(CC) $(CFLAGS) $(CDEBUG) $(FSANITIZE) $(INCS) -c $< -o $@

$(BOBJS_PATH)/%.o : $(BSRCS_PATH)/%.c
	@mkdir -p $(BOBJS_PATH)
	@$(CC) $(CFLAGS) $(CDEBUG) $(FSANITIZE) $(INCS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT_PATH)
	make -C $(MLX_PATH)
	$(MV_MMS_NAME)
	cp $(MLX_PATH)/mlx.h $(INCS_PATH)
	$(CC) $(CFLAGS) $(LIBFT) $(INCS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

bonus : $(BOBJS)
	make -C $(LIBFT_PATH)
	make -C $(MLX_PATH)
	$(MV_MMS_NAME)
	cp $(MLX_PATH)/mlx.h $(INCS_PATH)
	$(CC) $(CFLAGS) $(LIBFT) $(INCS) -o $(NAME) $(BOBJS) $(MLX_FLAGS)

clean :
	$(RM) $(OBJS_PATH) $(BOBJS_PATH)
	make -C $(LIBFT_PATH) fclean
	$(RM_MMS_NAME)
	make -C $(MLX_PATH) clean

fclean : clean
	$(RM) $(NAME)
	$(RM) screenshot.bmp

debug : $(OBJS)
	make -C $(LIBFT_PATH)
	make -C $(MLX_PATH)
	$(MV_MMS_NAME)
	cp $(MLX_PATH)/mlx.h $(INCS_PATH)
	$(CC) $(CFLAGS) $(LIBFT) $(CDEBUG) $(FSANITIZE) $(INCS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

bonus_debug : $(BOBJS)
	make -C $(LIBFT_PATH)
	make -C $(MLX_PATH)
	$(MV_MMS_NAME)
	cp $(MLX_PATH)/mlx.h $(INCS_PATH)
	$(CC) $(CFLAGS) $(LIBFT) $(CDEBUG) $(FSANITIZE) $(INCS) -o $(NAME) $(BOBJS) $(MLX_FLAGS)

re : fclean all

.PHONY : all clean fclean re
