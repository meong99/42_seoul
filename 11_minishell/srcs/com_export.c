#include "minishell.h"

static t_env	*find_key(char *key)
{
	t_env	*node;

	node = g_env;
	while (node)
	{
		if (ft_strncmp(node->key, key, ft_strlen(key)) == 0)
			return (node);
		node = node->next;
	}
	return (NULL);
}

static void	mapping_value(char *key, char *value)
{
	t_env	*node;

	node = find_key(key);
	if (node == NULL)
	{
		printf("env mapping error\n");
		exit(0);
	}
	free(node->value);
	node->value = ft_strdup(value);
}

static void	ft_putenv(char *key, char *value)
{
	t_env	*temp;

	temp = g_env;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node(key, value);
}

static void	export_internal(t_list *node)
{
	char	**split_var;
	t_env	*check_key;

	while (node)
	{
		if (check_first_char((char*)node->content) != RET_ERR_INT)
		{
			split_var = ft_split((char*)node->content, '=');
			check_key = find_key(split_var[0]);
			if (check_key == NOT_FOUND && !check_export_error(split_var[0], \
				(char*)node->content))
				ft_putenv(split_var[0], split_var[1]);
			else if (check_key)
				mapping_value(split_var[0], split_var[1]);
			ft_free(split_var, 0, true);
		}
		node = node->next;
	}
}

int	exe_export(t_commands *commands)
{
	t_list	*node;

	node = commands->arg;
	if (node == NULL)
		print_export_env();
	else
		export_internal(node);
	return (0);
}
