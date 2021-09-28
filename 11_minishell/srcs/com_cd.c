#include "minishell.h"

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
		str = ft_strjoin(tmp_str, " ");
		free(tmp_str);
		tmp_str = str;
		str = ft_strjoin(tmp_str, (char*)temp->content);
		free(tmp_str);
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
	err_code = chdir(str);
}