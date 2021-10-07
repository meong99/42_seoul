#include "minishell.h"

static void	print_echo(t_list *node, char *str, int option)
{
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

static int	set_option(t_list *node, char **str)
{
	*str = (char *)node->content;
	if (ft_strncmp(*str, "-n", 3) == 0)
	{
		node = node->next;
		*str = (char *)node->content;
		return (true);
	}
	return (false);
}

void	exe_echo(t_commands *commands)
{
	t_list	*node;
	char	*str;
	int		option;

	node = commands->arg;
	option = set_option(node, &str);
	print_echo(node, str, option);
}
