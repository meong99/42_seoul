#include "minishell.h"

void	exe_echo(t_commands *commands)
{
	t_list	*node;
	char	*str;
	int		option;

	option = false;
	node = commands->arg;
	str = (char *)node->content;
	if (ft_strncmp(str, "-n", 3) == 0)
	{
		node = node->next;
		str = (char *)node->content;
		option = true;
	}
	while (node)
	{
		printf("%s", str);
		node = node->next;
		if (node)
		{
			printf(" ");
			str = (char *)node->content;
		}
	}
	if (option == false)
		printf("\n");
}
