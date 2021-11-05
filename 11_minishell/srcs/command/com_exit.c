#include "minishell.h"

static void	print_err_exit(void)
{
	write(2, "exit\n", 5);
	write(2, "minishell: ", 11);
	write(2, "exit: ", 6);
	write(2, "too many arguments\n", 20);
	errno = 1;
}

static int	ret_arg_len(t_list *arg)
{
	int	i;

	i = 0;
	while (arg && ++i)
		arg = arg->next;
	return (i);
}

static int	check_numeric(t_list *arg)
{
	char	*str;

	while (arg)
	{
		str = (char *)arg->content;
		while (*str)
		{
			if (ft_isdigit(*str) == 0)
				return (false);
			str++;
		}
		arg = arg->next;
	}
	return (true);
}

void	exe_exit(t_list *arg)
{
	if (check_numeric(arg) == false)
	{
		write(2, "exit\n", 5);
		write(2, "minishell: ", 11);
		write(2, "exit: ", 6);
		write(2, arg->content, ft_strlen((char *)arg->content));
		write(2, ": numeric argument required\n", 29);
		errno = 255;
		tcsetattr(STDIN_FILENO, TCSANOW, &g_commands->oldterm);
		exit(errno);
	}
	else if (ret_arg_len(arg) > 1)
		print_err_exit();
	else
	{
		errno = ft_atoi((char *)arg->content);
		tcsetattr(STDIN_FILENO, TCSANOW, &g_commands->oldterm);
		exit(errno);
	}
}
