#include "minishell.h"

void	init_all(t_commands *commands)
{
	commands->arg = NULL;
	commands->com = NULL;
	commands->filename = NULL;
	commands->redirections = NULL;
	commands->com = NULL;
	commands->delimiter = NULL;
	commands->index = 0;
	commands->total_index = 0;
}
