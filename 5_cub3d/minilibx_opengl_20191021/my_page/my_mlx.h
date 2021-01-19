#ifndef MY_MLX_H
# define MY_MLX_H

#include "../mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include "key_macos.h"
#include "../../get_next_line/get_next_line.h"
#include "../../libft/libft.h"

#define X_EVENT_KEY_PRESS		2
#define X_EVENT_KEY_EXIT		17 //Exit program key code

#define KEY_ESC			53

# define TILE_SIZE 75
# define ROWS 11
# define COLS 15
# define WIDTH COLS * TILE_SIZE
# define HEIGHT ROWS * TILE_SIZE
# define TO_COORD(X, Y) ((int)floor(Y) * WIDTH + (int)floor(X))
# define CHARACTER 30
# define LEFT -1
# define UP -1
# define RIGHT 1
# define DOWN 1

typedef struct	s_img
{
	void	*img;
	int		*data;

	int		size_l;
	int		bpp;
	int		endian;
}				t_img;

typedef struct	s_game
{
	void	*mlx;
	void	*win;
	t_img	img;

	int		**map;
	int		char_mask_x;
	int		char_mask_y;
	int		char_x;
	int		char_y;
	int		move;
}				t_game;

//drow
void	draw_rectangle(t_game *game, int x, int y, int color);
void	draw_rectangles(t_game *game);
void	draw_character(t_game *game, int x, int y, int color);

//get_map
char	**get_map();

// init
void	atoi_mapi(char **c_map, int **map);
void	game_init(t_game *game);
void	window_init(t_game *game);
void	img_init(t_game *game);

//util
void	move_x(t_game *game, int dir);
void	move_y(t_game *game, int dir);

//main
int		main_loop(t_game *game);
int 	win_close(t_game *game);
int		deal_key(int key_code, t_game *game);

#endif