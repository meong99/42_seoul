#include "minishell.h"

static void	print_err(int err_code, char *arg)
{
	char	*str;

	if (err_code == 0)
		return ;
	str = strerror(errno);
	//표준에러로 출력해야 한다.
	printf("minishell: cd: %s: %s\n", arg, str);
}

void		exe_cd(t_commands *commands)
{
	char	*pwd;
	char	*str;
	int		err_code;

	pwd = getcwd(NULL, 0);
	str = (char *)commands->arg->content;
	err_code = chdir(str);
	print_err(err_code, str);
}
