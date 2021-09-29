#include "minishell.h"

static t_env	*new_node(char *key, char *value)
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
	node->value = ft_strtrim(value, "'");
	return (node);
}

static void		append_node(t_env *env, char **envp)
{
	t_env	*node;
	char	**spl_envp;

	while (*envp)
	{
		spl_envp = ft_split(*envp, '=');
		node = new_node(spl_envp[0], spl_envp[1]);
		env->next = node;
		env = env->next;
		envp++;
	}
}

t_env			*init_env(char **envp)
{
	t_env	*env;
	char	**spl_envp;

	spl_envp = ft_split(*envp, '=');
	env = new_node(spl_envp[0], spl_envp[1]);
	envp++;
	ft_free(spl_envp, 0, true);
	append_node(env, envp);
	return (env);
}

void			init_commands(t_commands *commands, t_env *env)
{
	commands->arg = NULL;
	commands->com = NULL;
	commands->filename = NULL;
	commands->redirections = NULL;
	commands->com = NULL;
	commands->delimiter = NULL;
	commands->index = 0;
	commands->count_pipe = 0;
	commands->env = env;
}
