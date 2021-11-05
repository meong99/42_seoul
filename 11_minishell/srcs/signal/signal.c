#include "minishell.h"

void	sig_handler(int signal)
{
	if (!g_commands || g_commands->sig_handle == true)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	errno = 1;
	signal = 0;
}
