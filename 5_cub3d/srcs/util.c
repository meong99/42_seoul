#include "cub3d.h"

void	remove_space_info(t_game *game)
{
	int i;

	i = -1;
	while (++i <= CEILING_COLOR)
	{
		ft_strtrim(game->info_map[i], " ");
	}
	
}

void	val_free(char **val, int i)
{
	if (i == 1)
	{
		free(*val);
		*val = 0;
	}
	else
	{
		while (*val)
		{
			free(*val);
			*val = 0;
			val++;
		}
		val = 0;
	}
}

int		*todigit(t_game *game, char *s, int index)
{
	int	*new_str;
	int	i;

	if (!s)
		return (NULL);
	i = -1;
	game->rows[index] = ft_strlen(s);
	if (!(new_str = malloc(sizeof(int) * game->rows[index])))
		return (NULL);
	while (s[++i])
		new_str[i] = s[i] - '0';
	return (new_str);
}

int		count_element(char **element)
{
	int i;

	i = 0;
	while (*element)
	{
		i++;
		element++;
	}
	return (i);
}

void	error_exit(int type)
{
	if (type == 1)
		printf("file open error\n");
	else if (type == 2)
		printf("invalid element\n");
	else if (type == 3)
		printf("to many characters\n");
	else if (type == 4)
		printf("not closed\n");
	else if (type == 5)
		printf("invalid character\n");
	else if (type == 6)
		printf("color count\n");
	else if (type == 7)
		printf("element count\n");
	else if (type == 8)
		printf("color value over\n");
	else if (type == 9)
		printf("overlapping error\n");
	exit(-1);
}
