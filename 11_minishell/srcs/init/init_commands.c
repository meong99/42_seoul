#include "minishell.h"

void	init_commands(t_commands *commands)
{
	commands->arg = NULL;
	commands->com = NULL;
	commands->redir_in = NULL;
	commands->redir_out = NULL;
	commands->filename_in = NULL;
	commands->filename_out = NULL;
	commands->com = NULL;
	commands->index = 0;
	commands->count_pipe = 0;
}
