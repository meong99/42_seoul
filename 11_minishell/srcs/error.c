#include "minishell.h"

void	print_err(char *com, t_list *arg_list)
{
	char	*str;
	char	*arg;

	if (errno == 0)
		return ;
	str = strerror(errno);
	if (errno == 2)
		printf("minishell: %s: %s\n",com, str);
	else
	{
		while (arg_list)
		{
			arg = (char *)arg_list->content;
			printf("%s: %s: %s\n",com, arg, str);
			arg_list = arg_list->next;
		}
	}
}
