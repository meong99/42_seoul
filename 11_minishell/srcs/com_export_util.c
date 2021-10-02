#include "minishell.h"

static t_env	*ret_befor(t_env *head, t_env *criteria)
{
	while (head)
	{
		if (head->next == criteria)
			return (head);
		head = head->next;
	}
	return (NULL);
}

static void	swap_node(t_env *env, t_env *set, t_env *compare)
{
	t_env	*temp;

	temp = ret_befor(*env->head, set);
	if (temp != NULL)
		temp->next = compare;
	temp = ret_befor(*env->head, compare);
	if (temp != NULL)
		temp->next = set;
	temp = set->next;
	set->next = compare->next;
	compare->next = temp;
}

void		sorting_export(t_env *env)
{
	t_env	*set;
	t_env	*compare;
	size_t	len;

	set = env;
	while (set->next)
	{
		compare = set->next;
		while (compare)
		{
			if (ft_strlen(compare->key) > ft_strlen(set->key))
				len = ft_strlen(compare->key);
			else
				len = ft_strlen(set->key);
			if (ft_strncmp(set->key, compare->key, len) > 0)
				swap_node(env, set, compare);
			compare = compare->next;
		}
		set = set->next;
	}
}