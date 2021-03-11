#include "cub3d.h"

void	var_free(void *var, int pointer_num, int index, int type)
{
	int i;

	i = -1;
	if (pointer_num == 1)
	{
		free(*((void**)var));
		*((void**)var) = 0;
	}
	else
	{
		if (type == TYPE_CHAR)
		{
			while (((char**)var)[index++])
				;
		}
		while (++i < index)
		{
			free(((void**)var)[i]);
		}
		free(var);
	}
}

void	*var_malloc(size_t size)
{
	void	*val;

	val = malloc(size);
	if (!val)
		error_exit("malloc error");
	return (val);
}
