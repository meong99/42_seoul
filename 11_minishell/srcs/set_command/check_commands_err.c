#include "minishell.h"

static void	parse_mapped(t_commands *commands, char *mapped, char *mark)
{
	char	*input;

	if (*mark == '<')
	{
		free(commands->redir_input);
		free(commands->redir_in);
		commands->redir_in = ft_strdup(mark);
		if (ft_strncmp(commands->redir_in, "<", 2) == 0)
		{
			input = redir_input(mapped);
			commands->redir_input = input;
			free(mapped);
		}
		else
			commands->redir_input = mapped;
	}
	else
	{
		free(commands->redir_out);
		free(commands->redir_out_file);
		commands->redir_out = ft_strdup(mark);
		commands->redir_out_file = mapped;
		make_file(mapped, commands);
	}
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
		mapped = mapping_dollar(commands, \
			(char *)target->content, commands->old_errno);
		if (mapped == NULL)
		{
			errno = 1;
			mapped = join_errmsg((char *)target->content, \
				"ambiguous redirect", 0, 0);
			ft_putstr_fd(mapped, STDERR_FILENO);
			free(mapped);
			return ;
		}
		parse_mapped(commands, mapped, (char *)mark->content);
		if (errno)
			return ;
		mark = mark->next;
		target = target->next;
	}
}

static int	check_systax(char *target)
{
	if (ft_strnstr_f(target, "<<", ft_strlen(target), check_quote))
		return (print_systax_err("<<"));
	else if (ft_strnstr_f(target, ">>", ft_strlen(target), check_quote))
		return (print_systax_err(">>"));
	else if (ft_strchr_f(target, '<', BOTH, check_quote))
		return (print_systax_err("<"));
	else if (ft_strchr_f(target, '>', BOTH, check_quote))
		return (print_systax_err(">"));
	else if (*target == '\0')
		return (print_systax_err("newline"));
	return (0);
}

static int	redir_check(t_commands *commands)
{
	char	*redirin;
	char	*redirout;
	char	*input;

	redirin = 0;
	redirout = 0;
	if (commands->redir_in)
		redirin = commands->redir_in;
	if (commands->redir_out)
		redirin = commands->redir_out;
	if (redirin && ft_strncmp(redirin, "<<", 2) == 0)
	{
		if (check_systax(redirin) != RET_ERR_INT)
			input = redir_heredoc(redirin);
	}
	else if (redirin && ft_strncmp(redirin, "<", 1) == 0)
			check_systax(redirin);
	else if (redirout && ft_strncmp(redirout, ">>", 2) == 0)
			check_systax(redirout);
	else if (redirout && ft_strncmp(redirout, ">", 1) == 0)
			check_systax(redirout);
	if (errno)
		return (RET_ERR_INT);
	return (0);
}

int	check_commands_err(t_commands *commands)
{
	if (redir_check(commands) != RET_ERR_INT)
		mapping_redir(commands);
	if (errno)
		return (RET_ERR_INT);
	return (0);
}