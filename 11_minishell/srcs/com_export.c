#include "minishell.h"

static t_env	*find_key(t_env *env, char *key)
{
	t_env	*node;

	node = env;
	while (node)
	{
		if (ft_strncmp(node->key, key, ft_strlen(key)) == 0)
			return (node);
		node = node->next;
	}
	return (NULL);
}

static void		mapping_value(t_env *env, char *key, char *value)
{
	t_env	*node;

	node = find_key(env, key);
	free(node->key);
	node->key = value;
}

static void		ft_putenv(t_env *env, char *key, char *value)
{
	while (env->next)
		env = env->next;
	env->next = malloc(sizeof(t_env));
	env->next->key = key;
	env->next->value = value;
}

static void		print_env(t_env *env)
{
	while (env)
	{
		printf("declare -x %s=\"%s\"\n", env->key, env->value);
		env = env->next;
	}
}

void			exe_export(t_commands *commands, t_env *env)
{
	char	*str;
	char	**split_var;
	t_list	*node;

	node = commands->arg;
	sorting_export(*env->head);
	if (node == NULL)
	{
		print_env(*env->head);
		return ;
	}
	while (node)
	{
		split_var = ft_split((char*)node->content, '=');
		str = getenv(split_var[0]);
		if (str == NULL)
			ft_putenv(*env->head, split_var[0], split_var[1]);
		else
			mapping_value(*env->head, split_var[0], split_var[1]);
		sorting_export(*env->head);
		node = node->next;
	}
}