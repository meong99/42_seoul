#include "minishell.h"

static t_env	*find_key(char *key)
{
	t_env	*index;

	index = g_env;
	while (index)
	{
		if (ft_strncmp(index->key, key, ft_strlen(key)) == 0)
			return (index);
		index = index->next;
	}
	return (NULL);
}

static void	mapping_value(char *key, char *value)
{
	t_env	*mapping;

	mapping = find_key(key);
	free(mapping->value);
	mapping->value = ft_strdup(value);
}

static void	ft_putenv(char *key, char *value)
{
	t_env	*index;

	index = g_env;
	while (index->next)
		index = index->next;
	index->next = new_env_node(key, value, g_env->env_num);
	(*g_env->env_num)++;
}

static void	export_internal(t_list *arg)
{
	char	**split_var;
	t_env	*check_key;

	while (arg)
	{
		if (check_first_char((char *)arg->content) != RET_ERR_INT)
		{
			split_var = ft_split((char *)arg->content, '=');
			check_key = find_key(split_var[0]);
			if (check_key == NOT_FOUND && !check_export_error(split_var[0], \
				(char *)arg->content))
				ft_putenv(split_var[0], split_var[1]);
			else if (check_key)
				mapping_value(split_var[0], split_var[1]);
			ft_free(split_var, 0, true);
		}
		arg = arg->next;
	}
}

int	exe_export(t_commands *commands)
{
	t_list	*arg;

	arg = commands->arg;
	if (arg == NULL)
		print_export_env();
	else
		export_internal(arg);
	return (0);
}
