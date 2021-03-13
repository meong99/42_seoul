#include "cub3d.h"

void	set_sprite(t_game *game)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	i = -1;
	game->ray.sprite_dist = (t_sprite_dist*)var_malloc(sizeof(t_sprite_dist) * game->info.sprite_num);
	while (++i < game->info.cols)
	{
		j = -1;
		while (++j < game->info.rows[i])
		{
			if (game->info.map[i][j] == '2')
			{
				game->ray.sprite_dist[k].x = 0.5 + j;
				game->ray.sprite_dist[k].y = 0.5 + i;
				game->ray.sprite_dist[k].dist = (int) \
					(pow(game->player.char_pos_x - game->ray.sprite_dist[k].x, 2) \
					+ pow(game->player.char_pos_y - game->ray.sprite_dist[k].y, 2));
				k++;
			}
		}
	}
	sprite_sort(game);
}

void	sprite_sort(t_game *game)
{
	game = 0;
}

void	sprite_cast(t_game *game)
{
	int		color;

	for(int i = 0; i < game->info.sprite_num; i++)
	{
		game->ray.sprite.sprite_x = game->ray.sprite_dist[i].x - game->player.char_pos_x;
		game->ray.sprite.sprite_y = game->ray.sprite_dist[i].y - game->player.char_pos_y;
		game->ray.sprite.inverse_determinant = 1.0 / (game->player.plane_x * game->player.dir_y -\
			game->player.dir_x * game->player.plane_y);
		game->ray.sprite.transform_x = game->ray.sprite.inverse_determinant *\
			(game->player.dir_y * game->ray.sprite.sprite_x - game->player.dir_x * game->ray.sprite.sprite_y);
		game->ray.sprite.transform_y = game->ray.sprite.inverse_determinant *\
			(-game->player.plane_y * game->ray.sprite.sprite_x + game->player.plane_x * game->ray.sprite.sprite_y);
		game->ray.sprite.sprite_screen_x = (int)((game->info.screen_width / 2) *\
			(1 + game->ray.sprite.transform_x / game->ray.sprite.transform_y));
		game->ray.sprite.sprite_height = abs((int)(game->info.screen_height / game->ray.sprite.transform_y));
		game->ray.sprite.sprite_draw_start_y = -game->ray.sprite.sprite_height / 2 + game->info.screen_height / 2;
		if(game->ray.sprite.sprite_draw_start_y < 0)
			game->ray.sprite.sprite_draw_start_y = 0;
		game->ray.sprite.sprite_draw_end_y = game->ray.sprite.sprite_height / 2 + game->info.screen_height / 2;
		if(game->ray.sprite.sprite_draw_end_y >= game->info.screen_height)
			game->ray.sprite.sprite_draw_end_y = game->info.screen_height - 1;
		game->ray.sprite.sprite_width = abs( (int) (game->info.screen_height / game->ray.sprite.transform_y));

		game->ray.sprite.sprite_draw_start_x = -game->ray.sprite.sprite_width / 2 + game->ray.sprite.sprite_screen_x;

		if(game->ray.sprite.sprite_draw_start_x < 0)
			game->ray.sprite.sprite_draw_start_x = 0;

		game->ray.sprite.sprite_draw_end_x = game->ray.sprite.sprite_width / 2 + game->ray.sprite.sprite_screen_x;

		if(game->ray.sprite.sprite_draw_end_x >= game->info.screen_width)
			game->ray.sprite.sprite_draw_end_x = game->info.screen_width - 1;
		for(int stripe = game->ray.sprite.sprite_draw_start_x; stripe < game->ray.sprite.sprite_draw_end_x; stripe++)
		{
			game->ray.sprite.sprite_tex_x = (int)(256 * (stripe - (-game->ray.sprite.sprite_width /\
				2 + game->ray.sprite.sprite_screen_x)) * game->tex_info[SPRITE].texture_width / game->ray.sprite.sprite_width) / 256;
			if(game->ray.sprite.transform_y > 0 && stripe > 0 && stripe < game->info.screen_width &&\
				game->ray.sprite.transform_y < game->ray.sprite_buf[stripe])
			{
				for(int y = game->ray.sprite.sprite_draw_start_y; y < game->ray.sprite.sprite_draw_end_y; y++)
				{
					game->ray.sprite.d = (y) * 256 - game->info.screen_height * 128 + game->ray.sprite.sprite_height * 128;
					game->ray.sprite.sprite_tex_y = ((game->ray.sprite.d * game->tex_info[SPRITE].texture_height) /\
						game->ray.sprite.sprite_height) / 256;
					color = game->tex_info[SPRITE].data[game->tex_info[SPRITE].texture_width *\
						game->ray.sprite.sprite_tex_y + game->ray.sprite.sprite_tex_x];
					if((color & 0x00FFFFFF) != 0)
						game->ray.buf[y][stripe] = color;
				}
			}
		}
	}
}
