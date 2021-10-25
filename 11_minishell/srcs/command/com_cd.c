#include "minishell.h"

static void	print_err_cd(int err_code, char *arg)
{
	char	*strerr;

	if (err_code == 0)
		return ;
	strerr = strerror(errno);
	write(2, "minishell: cd: ", 15);
	write(2, arg, ft_strlen(arg));
	write(2, ": ", 2);
	write(2, strerr, ft_strlen(strerr));
	write(2, "\n", 1);
}

void	exe_cd(t_commands *commands)
{
	char	*pwd;
	char	*str;
	int		err_code;

	pwd = getcwd(NULL, 0);
	str = (char *)commands->arg->content;
	err_code = chdir(str);
	print_err_cd(err_code, str);
	free(pwd);
}
