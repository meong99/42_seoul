#include "minishell.h"

static int	check_errno(t_commands *commands, char **str)
{
	if (errno || commands->com == NULL)
	{
		free_all(commands, str, commands->fd);
		return (1);
	}
	return (0);
}

static int	str_handler(char *str, struct termios *oldterm)
{
	if (str == NULL)
	{
		ft_putstr_fd("\x1b[1A", STDOUT_FILENO);
		ft_putstr_fd("\033[11C", STDOUT_FILENO);
		printf("exit\n");
		tcsetattr(STDIN_FILENO, TCSANOW, oldterm);
		exit(0);
	}
	if (*str == 0)
	{
		free(str);
		return (1);
	}
	if (*str)
		add_history(str);
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	t_commands		*commands;
	struct termios	oldterm;
	char			*str;

	ac = 0;
	av = 0;
	init_env_var(envp);
	terminal_handler(&oldterm);
	signal(SIGINT, sig_handler);
	while (1)
	{
		str = readline("\033[1;36mminishell> \033[0m ");
		if (str_handler(str, &oldterm))
			continue ;
		commands = parsing_handler(str);
		if (check_errno(commands, &str))
			continue ;
		if (set_commands(commands) == CHILD)
			break ;
		free_all(commands, &str, commands->fd);
	}
	return (0);
}
