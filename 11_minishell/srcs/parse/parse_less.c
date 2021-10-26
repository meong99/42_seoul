#include "minishell.h"

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

static char	*get_input(char *start, char *end)
{
	char	*filename;
	int		i;
	char	*input;

	i = 0;
	while (*start == ' ')
		start++;
	while (start[i] && start + i <= end)
		i++;
	filename = malloc(i + 1);
	ft_protect(filename);
	i = 0;
	while (start[i] && start + i <= end)
	{
		filename[i] = start[i];
		i++;
	}
	filename[i] = 0;
	ft_protect(filename);
	input = 0;
	filename = remove_quote(filename);
	if (check_systax(filename) != RET_ERR_INT)
		input = redir_input(filename);
	free(filename);
	return (input);
}

static char	*filename_range(char *start)
{
	char	*end;
	int		i;
	int		check_systax;

	i = 0;
	while (start[i] == ' ')
		i++;
	end = start + i;
	check_systax = 0;
	while (start[i])
	{
		end = start + i;
		if (check_systax && ft_strchr("< >", start[i]))
		{
			if (!check_quote(start, start + i, BOTH))
			{
				end--;
				break ;
			}
		}
		else if (!ft_strchr("<>", start[i]))
			check_systax++;
		i++;
	}
	return (end);
}

char	*parse_less(t_commands *commands, char *str)
{
	char	*start;
	char	*end;

	start = ft_strchr_f(str, '<', BOTH, check_quote);
	end = filename_range(start + 1);
	if (commands->redir_in)
	{
		free(commands->redir_in);
		commands->redir_in = NULL;
	}
	if (commands->redir_input)
	{
		free(commands->redir_input);
		commands->redir_input = NULL;
	}
	commands->redir_input = get_input(start + 1, end);
	commands->redir_in = ft_strdup("<");
	ft_protect(commands->redir_in);
	return (ft_cut(str, start, end));
}
