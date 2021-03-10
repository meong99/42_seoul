#include "cub3d.h"

void	sprite_init(t_info *info, t_ray *ray)
{
	ray->sprite_buf = (double*)var_malloc(sizeof(double) * info->screen_width);
}