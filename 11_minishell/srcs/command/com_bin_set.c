/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_bin_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:45:38 by mchae             #+#    #+#             */
/*   Updated: 2021/11/16 18:14:36 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_env	*find_key(char *key)
{
	t_env	*node;

	node = g_commands->env;
	while (node)
	{
		if (ft_strncmp(node->key, key, ft_strlen(key)) == 0)
			return (node);
		node = node->next;
	}
	return (NULL);
}

static char	*ret_path(t_commands *commands, char **path_arr)
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
			path = ft_strjoin(path_arr[i], "/");
			ft_protect(path);
			path = ft_strjoin_free(path, commands->com);
			ft_protect(path);
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
	t_env	*env_path;
	char	**path_arr;

	path = NULL;
	env_path = find_key("PATH");
	if (env_path != NULL)
	{
		path_arr = ft_split(env_path->value, ':');
		ft_protect(path_arr);
		path = ret_path(commands, path_arr);
		ft_free(path_arr, 0, true);
	}
	return (path);
}
