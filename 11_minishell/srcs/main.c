#include "minishell.h"

static int	check_errno(char **str)
{
	if (errno || g_commands->com == NULL)
	{
		free_all(str, g_commands->fd);
		return (1);
	}
	return (0);
}

static int	str_handler(char *str)
{
	if (str == NULL)
	{
		ft_putstr_fd("\x1b[1A", STDOUT_FILENO);
		ft_putstr_fd("\033[11C", STDOUT_FILENO);
		printf("exit\n");
		tcsetattr(STDIN_FILENO, TCSANOW, &g_commands->oldterm);
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
	t_env			*env;
	char			*str;
	struct termios	oldterm;
	int				old_errno;

	ac = 0;
	av = 0;
	env = init_env_var(envp);
	terminal_handler(&oldterm);
	signal(SIGINT, sig_handler);
	while (1)
	{
		ignore_sigint();
		old_errno = errno;
		str = readline("\033[1;36mminishell> \033[0m ");
		errno = 0;
		if (str_handler(str))
			continue ;
		parsing_handler(str, old_errno, env);
		g_commands->oldterm = oldterm;
		if (check_errno(&str))
			continue ;
		if (set_commands() == CHILD)
			break ;
		free_all(&str, g_commands->fd);
	}
	return (0);
}
