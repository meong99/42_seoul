NAME = cub3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCS = -I../../get_next_line -I../../libft -I../
MLX_FLAGS = -L../ -lmlx -framework OpenGL -framework AppKit 
LIBFT_DIR = ../../libft
LIBFT = -L../../libft -lft
GNL = -D BUFFER_SIZE=10
RM = rm -f
SRCS =	main.c\
		init.c\
		util.c\
		map.c\
		error.c\
		2d_image.c\
		ray.c\
		../../get_next_line/get_next_line.c\
		../../get_next_line/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
MAP_NAME_1 = map.cub

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -g $(GNL) -c $< -o $@

$(NAME) : $(OBJS)
	# make -C $(LIBFT_DIR)
	# make -C ..
	$(CC) $(CFLAGS) $(LIBFT) -o $(NAME) $(OBJS) $(MLX_FLAGS)

clean :
	$(RM) $(OBJS)
	# make -C $(LIBFT_DIR) fclean
	# make -C .. clean

fclean : clean
	$(RM) $(NAME)

leak : $(OBJS)
	# make -C $(LIBFT_DIR)
	# make -C ..
	$(CC) $(CFLAGS) $(LIBFT) -o $(NAME) $(OBJS) $(MLX_FLAGS) -fsanitize=address

re : fclean all

.PHONY : all clean fclean re
