#include "minishell.h"

static t_env	*deep_copy(void)
{
	t_env	*index;
	t_env	*temp;
	t_env	*env;

	index = g_env;
	env = new_env_node(index->key, index->value, g_env->env_num);
	temp = env;
	index = index->next;
	while (index)
	{
		temp->next = new_env_node(index->key, index->value, g_env->env_num);
		temp = temp->next;
		index = index->next;
	}
	return (env);
}

void	print_export_env(void)
{
	t_env	*temp;

	temp = deep_copy();
	sorting_export(temp, temp->next, &temp);
	while (temp)
	{
		printf("declare -x %s", temp->key);
		if (temp->value)
			printf("=\"%s\"", temp->value);
		printf("\n");
		temp = temp->next;
	}
	free(temp);
}
