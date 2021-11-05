#include "minishell.h"

void	init_commands(t_commands *commands, t_env *env)
{
	commands->com = NULL;
	commands->arg = NULL;
	commands->redir_lst_mark = NULL;
	commands->redir_lst_target = NULL;
	commands->redir_in = NULL;
	commands->redir_out = NULL;
	commands->redir_input = NULL;
	commands->redir_out_file = NULL;
	commands->env = env;
	commands->sig_handle = true;
}
