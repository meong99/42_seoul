#include "minishell.h"

char	*redir_heredoc(char *delimiter)
{
	char			*str;
	char			*result;

	result = ft_strdup("");
	ft_protect(result);
	while (true)
	{
		str = readline("> ");
		if (str == NULL)
			break ;
		if (*str && ft_strncmp(str, delimiter, ft_strlen(str)) == 0)
			break ;
		result = ft_strjoin_free(result, str);
		ft_protect(result);
		result = ft_strjoin_free(result, "\n");
		ft_protect(result);
		free(str);
	}
	free(str);
	return (result);
}
