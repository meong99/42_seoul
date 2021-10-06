#include "minishell.h"

void	exe_env(t_commands *commands)
{
	t_env	*temp;

	temp = g_env;
	while (temp)
	{
		printf("declare -x %s", temp->key);
		if (temp->value)
			printf("=\"%s\"", temp->value);
		printf("\n");
		temp = temp->next;
	}
	commands = 0;
}
