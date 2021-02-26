#include "cub3d.h"

void	char_free(char **val, int i)
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
void	int_free(int **val, int i)
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

void	*val_malloc(size_t size)
{
	void	*val;

	val = malloc(size);
	if (!val)
		error_exit("malloc error");
	return (val);
}
