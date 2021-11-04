#include "minishell.h"

static char	*parse_redir(t_commands *commands, char *str)
{
	int		i;
	char	*start;
	char	*end;

	i = -1;
	end = str;
	start = 0;
	while (end[++i])
	{
		if (errno)
			break ;
		if (ft_strchr("<>", end[i]) && !check_quote(str, end + i, BOTH))
		{
			end = end + i;
			if (!start)
				start = end;
			if (ft_strncmp(end, "<<", 2) == 0)
				end = parse_heredoc(commands, end);
			else if (ft_strncmp(end, "<", 1) == 0)
				end = parse_less(commands, end);
			else if (ft_strncmp(end, ">>", 2) == 0)
				end = parse_append(commands, end);
			else
				end = parse_greater(commands, end);
			i = -1;
		}
	}
	if (!start)
		return (ft_strdup(str));
	else
		return (ft_cut(str, start, end));
}

static void	mapping_redir(t_commands *commands)
{
	t_list	*mark;
	t_list	*target;
	char	*mapped;

	mark = commands->redir_lst_mark;
	target = commands->redir_lst_target;
	while (mark)
	{
		mapped = mapping_dollar((char *)target->content);
		if (*(char *)mark->content == '<')
		{
			free(commands->redir_input);
			free(commands->redir_in);
			commands->redir_in = ft_strdup((char *)mark->content);
			commands->redir_input = mapped;
		}
		else
		{
			free(commands->redir_out);
			free(commands->redir_out_file);
			commands->redir_out = ft_strdup((char *)mark->content);
			commands->redir_out_file = mapped;
		}
		mark = mark->next;
		target = target->next;
	}
}

static void	get_input(t_commands *commands)
{
	char	*input;

	if (commands->redir_input)
	{
		if (ft_strncmp(commands->redir_in, "<", 2) == 0)
		{
			input = redir_input(commands->redir_input);
			free(commands->redir_input);
			commands->redir_input = input;
		}
	}
}

char	*redir_handler(t_commands *commands, char *str)
{
	char	*except_redir;

	except_redir = parse_redir(commands, str);
	if (!errno)
		mapping_redir(commands);
	if (!errno)
		get_input(commands);
	return (except_redir);
}
