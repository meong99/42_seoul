#include "minishell.h"

t_env		*new_node(char *key, char *value)
{
	t_env	*node;

	node = malloc(sizeof(t_env));
	if (node == NULL)
	{
		printf("%s", strerror(errno));
		exit(errno);
	}
	node->key = ft_strdup(key);
	node->next = NULL;
	node->value = ft_strtrim(value, "'\"");
	return (node);
}

static void	append_node(char **envp)
{
	t_env	*node;
	char	**spl_envp;

	node = g_env;
	while (*envp)
	{
		spl_envp = ft_split(*envp, '=');
		node->next = new_node(spl_envp[0], spl_envp[1]);
		node = node->next;
		ft_free(spl_envp, 0, true);
		envp++;
	}
}

void		init_env_var(char **envp)
{
	char	**spl_envp;

	spl_envp = ft_split(*envp, '=');
	g_env = new_node(spl_envp[0], spl_envp[1]);
	envp++;
	ft_free(spl_envp, 0, true);
	append_node(envp);
}
