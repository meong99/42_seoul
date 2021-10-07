#include "minishell.h"

static void	print_err(int err_num, char *arg, char *err_mag)
{
	errno = err_num;
	//표쥰에러 출력
	printf("minishell: export: `%s': %s\n", arg, err_mag);
}

int	check_unset_error(char *key)
{
	int		is_err;

	is_err = 0;
	if (!ft_isalpha(*key) && *key != '_' && ++is_err)
		print_err(1, key, "not a valid identifier");
	while (*++key)
	{
		if (ft_isalnum(*key) == 0 && *key != '_' && ++is_err)
			print_err(1, key, "not a valid identifier");
	}
	if (is_err == true)
		return (RET_ERR_INT);
	else
		return (0);
}
