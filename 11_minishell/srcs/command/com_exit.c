#include "minishell.h"

static void	print_err_exit(void)
{
	//
	write(2, "Too many arg\n", 14);
	errno = 1;
	exit(errno);
}

static int	ret_arg_len(t_list *arg)
{
	int	i;

	i = 0;
	while (arg && ++i)
		arg = arg->next;
	return (i);
}

void	exe_exit(t_list *arg)
{
	if (arg == NULL)
		errno = 0;
	else
	{
		if (ret_arg_len(arg) > 1)
			print_err_exit();
		else
			errno = ft_atoi((char *)arg->content);
	}
	exit(errno);
}
