#include "minishell.h"

void	sig_handler(int signal)
{
	if (!g_commands || g_commands->sig_handle == true)
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (g_commands->sig_handle == false)
		ft_putstr_fd("\n", STDOUT_FILENO);
	errno = 1;
	signal = 0;
}
