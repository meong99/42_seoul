/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env_variable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:50:00 by mchae             #+#    #+#             */
/*   Updated: 2021/11/22 17:36:44 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*new_env_node(char *key, char *value, int *env_num)
{
	t_env	*node;

	node = malloc(sizeof(t_env));
	ft_protect(node);
	node->key = ft_strdup(key);
	ft_protect(key);
	node->next = NULL;
	node->value = ft_strtrim(value, "'");
	node->env_num = env_num;
	return (node);
}

static int	append_node(char **envp, t_env **env, int *env_num)
{
	t_env	*node;
	char	**spl_envp;
	int		num;

	num = 0;
	while (*envp)
	{
		spl_envp = ft_split(*envp, '=');
		ft_protect(spl_envp);
		if (num == 0)
		{
			node = new_env_node(spl_envp[0], spl_envp[1], env_num);
			*env = node;
		}
		else
		{
			node->next = new_env_node(spl_envp[0], spl_envp[1], env_num);
			node = node->next;
		}
		ft_free(spl_envp, 0, true);
		envp++;
		num++;
	}
	return (num);
}

t_env	*init_env_var(char **envp)
{
	int		*env_num;
	t_env	*env;

	env_num = malloc(sizeof(int));
	ft_protect(env_num);
	*env_num = append_node(envp, &env, env_num) + 1;
	return (env);
}
