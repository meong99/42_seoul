#include "cub3d.h"

void	move_char(t_game *game)
{
	game = 0;	
}

void	f_free(char **val, int i)
{
	if (i == 1)
	{
		free(*val);
		val = 0;
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

int		count_element(t_game *game)
{

}