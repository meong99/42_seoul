/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_bin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:45:41 by mchae             #+#    #+#             */
/*   Updated: 2021/11/25 19:01:50 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	copy_env(t_env *head, char **envp)
{
	int		i;

	i = 0;
	while (head)
	{
		envp[i] = ft_strdup(head->key);
		ft_protect(envp[i]);
		envp[i] = ft_strjoin_free(envp[i], "=");
		ft_protect(envp[i]);
		envp[i] = ft_strjoin_free(envp[i], head->value);
		ft_protect(envp[i]);
		i++;
		head = head->next;
	}
}

static char	**make_envp(t_env *head)
{
	char	**envp;

	envp = malloc(sizeof(char *) * (*head->env_num + 1));
	ft_protect(envp);
	envp[*head->env_num - 1] = NULL;
	copy_env(head, envp);
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

	envp = make_envp(commands->env);
	argv = make_argv(commands);
	argv[0] = set_path(commands);
	if (execve(argv[0], argv, envp) == -1)
		check_bin_error(commands->com, argv[0]);
	ft_free(envp, 0, true);
	ft_free(argv, 0, true);
}
