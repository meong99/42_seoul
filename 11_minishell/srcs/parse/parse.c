#include "minishell.h"

static void	parse_redir_in(char *redir, char *target, t_commands *commands)
{
	if (ft_strncmp("<", redir, 2) == 0)
	{
		if (commands->redir_in)
		{
			free(commands->redir_in);
			free(commands->redir_in_target);
		}
		commands->redir_in = ft_strdup(redir);
		commands->redir_in_target = redir_input(target);
	}
	else
	{
		if (commands->redir_in)
		{
			free(commands->redir_in);
			free(commands->redir_in_target);
		}
		commands->redir_in = ft_strdup(redir);
		commands->redir_in_target = redir_heredoc(target);
	}
}

static void	parse_redir_out(char *redir, char *target, t_commands *commands)
{
	if (commands->redir_out)
		free(commands->redir_out);
	if (commands->redir_out_target)
		free(commands->redir_out_target);
	commands->redir_out = ft_strdup(redir);
	commands->redir_out_target = ft_strdup(target);
}

static void	split_space(char *str, t_commands *commands)
{
	char	**result;
	int		i;

	i = -1;
	result = ft_split_f(str, ' ', check_quote);
	while (result[++i])
	{
		if (ft_strnstr("<<", result[i], 3))
		{
			parse_redir_in(result[i], result[i + 1], commands);
			i++;
		}
		else if (ft_strnstr(">>", result[i], 3))
		{
			parse_redir_out(result[i], result[i + 1], commands);
			i++;
		}
		else if (commands->com == NULL)
			commands->com = ft_strdup(result[i]);
		else
			ft_lstadd_back(&commands->arg, ft_lstnew(ft_strdup(result[i])));
	}
	ft_free(result, 0, true);
}

t_commands	*parsing_handler(char *str)
{
	t_commands	*commands;
	char		**spl_pipe;
	char		*except_redir;
	int			i;
	int			redir;

	spl_pipe = ft_split_f(str, '|', check_quote);
	if (ft_strchr_f(str, '|', check_quote))
		commands = parse_pipe(str, spl_pipe);
	i = -1;
	while (spl_pipe[++i])
	{
		redir = check_redir(spl_pipe[i]);
		except_redir = parse_redir(commands, spl_pipe[i], redir);
	}
}
