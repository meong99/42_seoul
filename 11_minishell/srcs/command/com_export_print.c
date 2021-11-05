#include "minishell.h"

static t_env	*deep_copy(void)
{
	t_env	*index;
	t_env	*temp;
	t_env	*env;

	index = g_commands->env;
	env = new_env_node(index->key, index->value, NULL);
	temp = env;
	index = index->next;
	while (index)
	{
		temp->next = new_env_node(index->key, index->value, NULL);
		temp = temp->next;
		index = index->next;
	}
	return (env);
}

void	print_export_env(void)
{
	t_env	*node;
	t_env	*temp;

	node = deep_copy();
	sorting_export(node, node->next, &node);
	temp = node;
	while (temp)
	{
		printf("declare -x %s", temp->key);
		if (temp->value)
			printf("=\"%s\"", temp->value);
		printf("\n");
		temp = temp->next;
	}
	while (node)
	{
		temp = node->next;
		free(node->key);
		free(node->value);
		free(node);
		node = temp;
	}
}
