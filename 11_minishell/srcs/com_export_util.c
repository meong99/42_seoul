#include "minishell.h"

static t_env	*ret_befor(t_env *criteria)
{
	t_env	*head;

	head = g_env;
	while (head)
	{
		if (head->next == criteria)
			return (head);
		head = head->next;
	}
	return (NULL);
}

static void	swap_node(t_env *set, t_env *compare)
{
	t_env	*befor_set;
	t_env	*befor_com;
	t_env	*temp;

	befor_set = ret_befor(set);
	befor_com = ret_befor(compare);
	if (befor_set == NULL)
		g_env = compare;
	else
		befor_set->next = compare;
	befor_com->next = set;
	temp = set->next;
	set->next = compare->next;
	compare->next = temp;
}

static size_t	ret_longer(char *str_1, char *str_2)
{
	if (ft_strlen(str_1) > ft_strlen(str_2))
		return (ft_strlen(str_1));
	else
		return (ft_strlen(str_2));
}

void	sorting_export()
{
	t_env	*set;
	t_env	*compare;
	t_env	*temp;
	size_t	len;

	set = g_env;
	while (set->next)
	{
		compare = set->next;
		while (compare)
		{
			len = ret_longer(set->key, compare->key);
			if (ft_strncmp(set->key, compare->key, len) > 0)
			{
				swap_node(set, compare);
				temp = set;
				set = compare;
				compare = temp;
			}
			compare = compare->next;
		}
		set = set->next;
	}
}
