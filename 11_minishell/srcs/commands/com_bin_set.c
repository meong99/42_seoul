#include "minishell.h"

static t_env	*find_key(char *key)
{
	t_env	*node;

	node = g_env;
	while (node)
	{
		if (ft_strncmp(node->key, key, ft_strlen(key)) == 0)
			return (node);
		node = node->next;
	}
	return (NULL);
}

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
	char	**path_arr;

	path_arr = ft_split(find_key("PATH")->value, ':');
	path = ret_path(commands, path_arr);
	return (path);
}
