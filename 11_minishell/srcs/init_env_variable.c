#include "minishell.h"

t_env	*new_env_node(char *key, char *value, int *env_num)
{
	t_env	*node;

	node = malloc(sizeof(t_env));
	if (node == NULL)
	{
		//err
		printf("%s", strerror(errno));
		exit(errno);
	}
	node->key = ft_strdup(key);
	node->next = NULL;
	node->value = ft_strtrim(value, "'");
	node->env_num = env_num;
	return (node);
}

static int	append_node(char **envp)
{
	t_env	*node;
	char	**spl_envp;
	int		env_num;

	env_num = 0;
	node = g_env;
	while (*envp)
	{
		spl_envp = ft_split(*envp, '=');
		node->next = new_env_node(spl_envp[0], spl_envp[1], g_env->env_num);
		node = node->next;
		ft_free(spl_envp, 0, true);
		envp++;
		env_num++;
	}
	return (env_num);
}

void	init_env_var(char **envp)
{
	char	**spl_envp;
	int		*env_num;

	env_num = malloc(sizeof(int));
	if (env_num == NULL)
	{
		//err
		printf("asd\n");
		exit(errno);
	}
	spl_envp = ft_split(*envp, '=');
	g_env = new_env_node(spl_envp[0], spl_envp[1], env_num);
	envp++;
	ft_free(spl_envp, 0, true);
	*env_num = append_node(envp) + 1;
}
