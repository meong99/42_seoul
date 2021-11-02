#include "minishell.h"

void	init_commands(t_commands *commands)
{
	commands->com = NULL;
	commands->arg = NULL;
	commands->redir_in = NULL;
	commands->redir_out = NULL;
	commands->redir_input = NULL;
	commands->redir_out_file = NULL;
}
