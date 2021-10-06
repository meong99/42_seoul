#include "minishell.h"

void	exe_env(t_commands *commands)
{
	t_env	*temp;

	temp = g_env;
	while (temp)
	{
		if (temp->value)
			printf("%s=%s\n", temp->key, temp->value);
		temp = temp->next;
	}
	commands = 0;
}
