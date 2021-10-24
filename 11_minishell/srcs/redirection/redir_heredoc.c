#include "minishell.h"

char	*redir_heredoc(char *delimiter)
{
	char	*str;
	char	*result;

	if (delimiter == 0)
	{
		errno = 258;
		return (NULL);
	}
	result = ft_strdup("");
	while (true)
	{
		str = readline("> ");
		if (str == NULL)
			return (result);
		if (*str && ft_strncmp(str, delimiter, ft_strlen(str)) == 0)
			break ;
		result = ft_strjoin_free(result, str);
		result = ft_strjoin_free(result, "\n");
		free(str);
	}
	free(str);
	return (result);
}
