/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_bin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:45:41 by mchae             #+#    #+#             */
/*   Updated: 2021/11/09 21:12:28 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	copy_env(char **envp)
{
	t_env	*index;
	int		i;

	i = 0;
	index = g_commands->env;
	while (index)
	{
		envp[i] = ft_strdup(index->key);
		ft_protect(envp[i]);
		envp[i] = ft_strjoin_free(envp[i], "=");
		ft_protect(envp[i]);
		envp[i] = ft_strjoin_free(envp[i], index->value);
		ft_protect(envp[i]);
		i++;
		index = index->next;
	}
}

static char	**make_envp(void)
{
	char	**envp;
	t_env	*env;

	env = g_commands->env;
	envp = malloc(sizeof(char *) * (*env->env_num + 1));
	ft_protect(envp);
	envp[*env->env_num] = NULL;
	copy_env(envp);
	return (envp);
}

static char	**alloc_argv(t_list *arg)
{
	int		i;
	char	**argv;

	i = 0;
	while (arg && ++i)
		arg = arg->next;
	argv = malloc(sizeof(char *) * (i + 2));
	ft_protect(argv);
	argv[i + 1] = NULL;
	return (argv);
}

static char	**make_argv(t_commands *commands)
{
	char	**argv;
	int		i;
	t_list	*arg_list;

	argv = alloc_argv(commands->arg);
	i = 1;
	arg_list = commands->arg;
	while (arg_list)
	{
		argv[i] = ft_strdup((char *)arg_list->content);
		ft_protect(argv[i]);
		arg_list = arg_list->next;
		i++;
	}
	return (argv);
}

void	exe_bin(t_commands *commands)
{
	char	**envp;
	char	**argv;

	envp = make_envp();
	argv = make_argv(commands);
	argv[0] = set_path(commands);
	if (execve(argv[0], argv, envp) == -1)
		check_bin_error(commands->com);
	ft_free(envp, 0, true);
	ft_free(argv, 0, true);
}
