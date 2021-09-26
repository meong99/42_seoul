#include "minishell.h"

void	init_all(t_commands *commands)
{
	commands->arg = NULL;
	commands->com = NULL;
	commands->filename = NULL;
	commands->redirections = NULL;
}