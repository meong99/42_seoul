#include "minishell.h"

void	init_commands(t_commands *commands)
{
	commands->arg = NULL;
	commands->com = NULL;
	commands->redir_in = NULL;
	commands->redir_out = NULL;
	commands->redir_in_target = NULL;
	commands->redir_out_target = NULL;
	commands->com = NULL;
	commands->index = 0;
	commands->count_pipe = 0;
}
