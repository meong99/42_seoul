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

t_env			*init_env(char **envp)
{
	t_env	*env;
	t_env	*node;
	

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
