#include "cub3d.h"

void	char_free(char **val, int type)
{
	if (type == 1)
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
void	int_free(int **val, int type, int index)
{
	int		i;

	i = -1;
	if (type == 1)
	{
		free(*val);
		*val = 0;
		index = 0;
	}
	else
	{
		while (++i < index)
		{
			free(val[i]);
			val[i] = 0;
		}
		val = 0;
	}
}

void	*val_malloc(size_t size)
{
	void	*val;

	val = malloc(size);
	if (!val)
		error_exit("malloc error");
	return (val);
}
