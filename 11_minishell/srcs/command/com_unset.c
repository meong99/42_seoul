#include "minishell.h"

static t_env	*ret_befor(t_env *criteria)
{
	t_env	*node;

	node = g_commands->env;
	while (node)
	{
		if (node->next == criteria || node == criteria)
			return (node);
		node = node->next;
	}
	return (NULL);
}

static t_env	*find_key(char *key)
{
	t_env	*node;

	node = g_commands->env;
	while (node)
	{
		if (ft_strncmp(node->key, key, ft_strlen(key)) == 0)
			return (node);
		node = node->next;
	}
	return (NULL);
}

static void	remove_env(char *key)
{
	t_env	*node;
	t_env	*before;

	node = find_key(key);
	if (node == NULL)
		return ;
	before = ret_befor(node);
	before->next = node->next;
	free(node->key);
	free(node->value);
	free(node);
	(*g_commands->env->env_num)--;
}

int	exe_unset(t_commands *commands)
{
	t_list	*node;

	node = commands->arg;
	while (node)
	{
		if (check_unset_error((char *)node->content) != RET_ERR_INT)
			remove_env((char *)node->content);
		node = node->next;
	}
	return (0);
}
