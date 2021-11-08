#include "minishell.h"

static void	print_err_cd(int err_code, char *arg)
{
	char	*strerr;

	if (err_code == 0)
		return ;
	strerr = strerror(errno);
	ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(strerr, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
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
