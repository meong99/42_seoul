#include "minishell.h"

static t_env	*deep_copy(void)
{
	t_env	*index;
	t_env	*temp;
	t_env	*env;
	int		*env_num;

	index = g_env;
	env_num = malloc(sizeof(int));
	*env_num = *g_env->env_num;
	env = new_env_node(index->key, index->value, g_env->env_num);
	temp = env;
	index = index->next;
	while (index)
	{
		temp->next = new_env_node(index->key, index->value, env_num);
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
	free(node->env_num);
	while (node)
	{
		temp = node->next;
		free(node->key);
		free(node->value);
		node = temp;
	}
}
