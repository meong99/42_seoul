#include "my_mlx.h"

static void pars(int fd, char **map_info)
{
	int i;

	i = 0;
    while (get_next_line(fd, &map_info[i++]) > 0)
		;
}

char **get_map()
{
    int     fd;
	char	*temp;
	char	**map_info;
	int		i;

	i = 1;
    fd = open("map.cub", O_RDONLY);
	while (get_next_line(fd, &temp) > 0)
		i++;
	close(fd);
    fd = open("map.cub", O_RDONLY);
	map_info = (char**)malloc(sizeof(char*) * i);
    pars(fd, map_info);
	close(fd);
	
	return (map_info);
}
