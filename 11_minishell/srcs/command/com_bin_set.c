/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_bin_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:45:38 by mchae             #+#    #+#             */
/*   Updated: 2021/11/25 19:07:03 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_env	*find_key(t_env *head, char *key)
{
	while (head)
	{
		if (ft_strncmp(head->key, key, ft_strlen(key)) == 0)
			return (head);
		head = head->next;
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
	char		*path;
	t_env		*env_path;
	char		**path_arr;
	struct stat	buf;

	path = NULL;
	env_path = find_key(commands->env, "PATH");
	if (env_path != NULL)
	{
		path_arr = ft_split(env_path->value, ':');
		ft_protect(path_arr);
		path = ret_path(commands, path_arr);
		ft_free(path_arr, 0, true);
	}
	else if (stat(commands->com, &buf) == 0)
		path = commands->com;
	return (path);
}
