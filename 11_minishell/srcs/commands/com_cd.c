#include "minishell.h"

static void	print_err(int err_code)
{
	char	*str;

	if (err_code == 0)
		return ;
	str = strerror(errno);
	//표준에러로 출력해야 한다.
	printf("minishell: %s\n", str);
	free(str);
}

static char	*join_arg(t_list *arg)
{
	t_list	*temp;
	char	*tmp_str;
	char	*str;

	temp = arg;
	str = ft_strdup("");
	if (temp == NULL)
		return (RET_ERR_NULL);
	while (temp)
	{
		tmp_str = str;
		str = ft_strjoin(tmp_str, (char*)temp->content);
		free(tmp_str);
		if (temp->next != NULL)
		{
			tmp_str = str;
			str = ft_strjoin(tmp_str, " ");
			free(tmp_str);
		}
		temp = temp->next;
	}
	return (str);
}

void		exe_cd(t_commands *commands)
{
	char	*pwd;
	char	*str;
	int		err_code;

	pwd = getcwd(NULL, 0);
	str = join_arg(commands->arg);
	printf("%s\n", str);
	err_code = chdir(str);
	print_err(err_code);
	free(str);
}
