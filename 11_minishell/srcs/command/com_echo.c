#include "minishell.h"

static void	print_echo(t_list *node, int option)
{
	char	*str;

	while (node)
	{
		str = (char *)node->content;
		if (str == NULL)
			str = "";
		printf("%s", str);
		node = node->next;
		if (node)
			printf(" ");
	}
	if (option == false)
		printf("\n");
}

static int	set_option(t_list *node)
{
	if (ft_strncmp((char *)node->content, "-n", 3) == 0)
		return (true);
	return (false);
}

void	exe_echo(t_commands *commands)
{
	t_list	*node;
	int		option;

	node = commands->arg;
	option = set_option(node);
	print_echo(node + option, option);
}
