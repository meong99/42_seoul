#include "cub3d.h"

static void pars(int fd, char **map_info)
{
	int i;

	i = 0;
    while (get_next_line(fd, &map_info[i++]) > 0)
		if (i < 1)
			put_error("gnl error!");
	
}

char **get_map(t_game *game)
{
    int     fd;
	char	*temp;
	char	**map_info;
	int		i;

	i = 1;
    if (!(fd = open("map.cub", O_RDONLY)))
		put_error("file open error!");
	while (get_next_line(fd, &temp) > 0)
		i++;
	if ((game->map_rows = i - MAP) < 1)
		put_error("gnl error!");
	if (!(game->map_cols =(int*)malloc(sizeof(int) * game->map_rows)))
		put_error("map cols malloc error!");
	close(fd);
    if (!(fd = open("map.cub", O_RDONLY)))
		put_error("file open error!");
	if (!(map_info = (char**)malloc(sizeof(char*) * i)))
		put_error("map_info malloc error!");
    pars(fd, map_info);
	
	return (map_info);
}