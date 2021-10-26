#include "minishell.h"

void	exe_pwd(void)
{
	char	*str;

	str = getcwd(NULL, 0);
	ft_protect(str);
	printf("%s\n", str);
	free(str);
}
