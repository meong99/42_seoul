NAME	= cub3D

SRC_NAME = main.c \
		   init.c \
		   exit.c \
		   get_next_line.c \
		   keys.c\
		   parse_config.c\
		   parse_line.c \
		   parse_str_util.c \
		   texture.c \
		   player_move.c \
		   calc_raycasting.c \
		   calc_sprite.c \
		   calc_utils.c \
		   mapcheck.c \
		   draw.c \
		   utils.c \
		   free_utils.c \
		   screenshot.c
SRC_PATH = ./src
SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = ./obj
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@gcc $(CFLAG) $(HEADER) -o $@ -c $<

BSRC_NAME = main_bonus.c \
		   init_bonus.c \
		   exit_bonus.c \
		   get_next_line_bonus.c \
		   keys_bonus.c\
		   parse_config_bonus.c\
		   parse_line_bonus.c \
		   parse_str_util_bonus.c \
		   texture_bonus.c \
		   player_move_bonus.c \
		   calc_raycasting_bonus.c \
		   calc_sprite_bonus.c \
		   calc_utils_bonus.c \
		   mapcheck_bonus.c \
		   draw_bonus.c \
		   utils_bonus.c \
		   free_utils_bonus.c \
		   screenshot_bonus.c \
		   music_bonus.c \
		   catch_fish_bonus.c
BSRC_PATH = ./bonus
BSRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

BOBJ_NAME = $(BSRC_NAME:.c=.o)
BOBJ_PATH = ./bobj
BOBJ = $(addprefix $(BOBJ_PATH)/, $(BOBJ_NAME))
$(BOBJ_PATH)/%.o: $(BSRC_PATH)/%.c
	@mkdir $(BOBJ_PATH) 2> /dev/null || true
	@gcc $(CFLAG) $(HEADER) -o $@ -c $<

SCREENSHOT = screenshot.bmp

HEADER	= -I./includes

CFLAG	= -Wall -Wextra -Werror

LIBFT	= libft.a

LIBMLX	= libmlx.a

MLX	= -framework OpenGL -framework Appkit

LIBS	= -L./lib/libft -lft -L./lib/mlx -lmlx

RM	= rm -rf

all	: $(NAME)

$(NAME)	: $(OBJ) $(LIBFT) $(LIBMLX)
	gcc -o $(NAME) $(OBJ) $(HEADER) $(CFLAG) $(LIBS) $(MLX)

bonus	: $(BOBJ) $(LIBFT) $(LIBMLX)
	gcc -o $(NAME) $(BOBJ) $(HEADER) $(CFLAG) $(LIBS) $(MLX)

$(LIBFT):
	$(MAKE) -C lib/libft

$(LIBMLX):
	$(MAKE) -C lib/mlx

clean	:
	$(MAKE) -C lib/libft clean
	$(MAKE) -C lib/mlx clean
	rm -rf $(OBJ_PATH) $(BOBJ_PATH) $(SCREENSHOT)

fclean	: clean
	$(MAKE) -C lib/libft fclean
	rm -rf $(NAME)

re		: fclean all

.PHONY: all clean fclean re
