#include "minishell.h"

static void	copy_env(char **envp)
{
	t_env	*index;
	int		i;

	i = 0;
	index = g_env;
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

	envp = malloc(sizeof(char *) * (*g_env->env_num + 1));
	ft_protect(envp);
	envp[*g_env->env_num] = NULL;
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
	char	*path;

	envp = make_envp();
	argv = make_argv(commands);
	path = set_path(commands);
	argv[0] = path;
	if (execve(path, argv, envp) == -1)
		check_bin_error(commands->com);
	free(path);
	ft_free(envp, 0, true);
	ft_free(argv, 0, true);
}
