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
	free(node->key);
	node->key = ft_strdup(value);
}

static void	ft_putenv(char *key, char *value)
{
	t_env	*temp;

	temp = g_env;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node(key, value);
}

static int	print_env()
{
	t_env	*temp;

	temp = g_env;
	while (temp)
	{
		printf("declare -x %s=\"%s\"\n", temp->key, temp->value);
		temp = temp->next;
	}
	return (0);
}

int	exe_export(t_commands *commands)
{
	char	*str;
	char	**split_var;
	t_list	*node;

	node = commands->arg;
	sorting_export();
	if (node == NULL)
		return(print_env());
	while (node)
	{
		split_var = ft_split((char*)node->content, '=');
		str = getenv(split_var[0]);
		if (str == NOT_FOUND && !check_export_error(split_var[0], \
			(char*)node->content))
			ft_putenv(split_var[0], split_var[1]);
		else if (str)
			mapping_value(split_var[0], split_var[1]);
		sorting_export();
		ft_free(split_var, 0, true);
		node = node->next;
	}
	return (0);
}
