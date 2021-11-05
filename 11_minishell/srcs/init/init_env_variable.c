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

static int	append_node(char **envp, t_env *env)
{
	t_env	*node;
	char	**spl_envp;
	int		env_num;

	env_num = 0;
	node = env;
	while (*envp)
	{
		spl_envp = ft_split(*envp, '=');
		ft_protect(spl_envp);
		node->next = new_env_node(spl_envp[0], spl_envp[1], node->env_num);
		node = node->next;
		ft_free(spl_envp, 0, true);
		envp++;
		env_num++;
	}
	return (env_num);
}

t_env	*init_env_var(char **envp)
{
	char	**spl_envp;
	int		*env_num;
	t_env	*env;

	env_num = malloc(sizeof(int));
	ft_protect(env_num);
	spl_envp = ft_split(*envp, '=');
	ft_protect(spl_envp);
	env = new_env_node(spl_envp[0], spl_envp[1], env_num);
	envp++;
	ft_free(spl_envp, 0, true);
	*env_num = append_node(envp, env) + 1;
	return (env);
}
