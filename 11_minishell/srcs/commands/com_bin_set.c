#include "minishell.h"

static char	*ret_path(t_commands *commands, char *path_arr[])
{
	char		*path;
	struct stat	buf;
	int			i;

	if (stat(commands->com, &buf) == 0)
		path = commands->com;
	else
	{
		i = -1;
		while (path_arr[++i])
		{
			path = ft_strjoin(path_arr[i], commands->com);
			if (stat(path, &buf) == 0)
				return (path);
			free(path);
		}
	}
	return (commands->com);
}

char	*set_path(t_commands *commands)
{
	char	*path;
	char	*path_arr[6];

	path_arr[0] = "/bin/";
	path_arr[1] = "/usr/bin/";
	path_arr[2] = "/usr/local/bin/";
	path_arr[3] = "/sbin/";
	path_arr[4] = "/usr/sbin/";
	path_arr[5] = NULL;
	path = ret_path(commands, path_arr);
	return (path);
}
