#include "minishell.h"

static void	make_file(char *filename)
{
	int		fd;
	char	*str;

	fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		str = strerror(errno);
		write(2, "minishell: ", 11);
		write(2, filename, ft_strlen(filename));
		write(2, ": ", 2);
		write(2, str, ft_strlen(str));
		write(2, "\n", 1);
		errno = 1;
	}
	close(fd);
	return ;
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

static char	*get_filename(char *start, char *end)
{
	char	*filename;
	int		i;

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
	filename = remove_quote(filename);
	if (check_systax(filename) != RET_ERR_INT)
		make_file(filename);
	return (filename);
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

char	*parse_append(t_commands *commands, char *str)
{
	char	*start;
	char	*end;

	start = ft_strnstr_f(str, ">>", ft_strlen(str), check_quote);
	end = filename_range(start + 2);
	if (commands->redir_out)
	{
		free(commands->redir_out);
		commands->redir_out = NULL;
	}
	if (commands->redir_out_file)
	{
		free(commands->redir_out_file);
		commands->redir_out_file = NULL;
	}
	commands->redir_out_file = get_filename(start + 2, end);
	commands->redir_out = ft_strdup(">>");
	ft_protect(commands->redir_out);
	return (ft_cut(str, start, end));
}
