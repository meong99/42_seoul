#include "minishell.h"

static t_env	*find_key(t_env *env, char *key)
{
	t_env	*index;

	index = env;
	while (index)
	{
		if (ft_strncmp(index->key, key, ft_strlen(key)) == 0)
			return (index);
		index = index->next;
	}
	return (NULL);
}

static void	mapping_value(t_env *env, char *key, char *value)
{
	t_env	*temp;

	temp = find_key(env, key);
	free(temp->key);
	temp->key = value;
}

static void	ft_putenv(t_env *env, char *key, char *value)
{
	while (env->next)
		env = env->next;
	env->next = malloc(sizeof(t_env));
	env->next->key = key;
	env->next->value = value;
}

void	print_env(t_env *env)
{
	while (env)
	{
		printf("declare -x %s=\"%s\"", env->key, env->value);
		env = env->next;
	}
}

void	exe_export(t_commands *commands, t_env *env)
{
	char	*str;
	char	**split_var;
	t_list	*index;

	index = commands->arg;
	while (index)
	{
		split_var = ft_split((char*)index->content, '=');
		str = getenv(split_var[0]);
		if (str == NULL)
			ft_putenv(env, split_var[0], split_var[1]);
		else
			mapping_value(env, split_var[0], split_var[1]);
		index = index->next;
	}
}