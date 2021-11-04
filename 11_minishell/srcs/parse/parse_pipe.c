#include "minishell.h"

t_commands	*parse_pipe(char **spl)
{
	int			pipe_num;
	int			i;
	t_commands	*commands;

	pipe_num = 0;
	while (spl[pipe_num])
		pipe_num++;
	commands = malloc(sizeof(t_commands) * pipe_num);
	ft_protect(commands);
	i = -1;
	while (++i < pipe_num)
	{
		commands[i].command_num = pipe_num;
		commands[i].index = i;
	}
	return (commands);
}
