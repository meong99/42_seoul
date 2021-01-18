#include "cub3d.h"

void	put_error(const char *str)
{
	perror(str);
	exit(-1);
}
void	atoi_mapi(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (i < game->map_rows)
	{
		j = 0;
		while (j < game->map_cols[i])
		{
			if (game->map[i][j] == 'N')
				game->map[i][j] = game->map_info[MAP + i][j];
			else
				game->map[i][j] = game->map_info[MAP + i][j] - '0';
			j++;
		}
		i++;
	}
}

void	get_pos(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (i < game->map_rows)
	{
		j = 0;
		while (j < game->map_cols[i])
		{
			if (game->map[i][j] == 'N')
			{
				game->pos_x = i;
				game->pos_y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}