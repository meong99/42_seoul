#include "cub3d.h"

void	move_char(t_game *game)
{
	game = 0;	
}

void	str_free(char **val)
{
	free(*val);
	*val = 0;
}

int		*todigit(char *s)
{
	int	*new_str;
	int	i;

	if (!s)
		return (NULL);
	i = -1;
	if (!(new_str = malloc(sizeof(int) * ft_strlen(s))))
		return (NULL);
	while (s[++i])
		new_str[i] = s[i] - '0';
	return (new_str);
}