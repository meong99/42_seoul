#include "minishell.h"

static void	print_err(int err_num, char *arg, char *err_mag)
{
	errno = err_num;
	//표쥰에러 출력
	printf("minishell: export: `%s': %s\n", arg, err_mag);
}

static int	check_key(char *key, char *arg)
{
	while (*++key)
	{
		if (ft_isalnum(*key) == 0 && *key != '_')
		{
			print_err(1, arg, "not a valid identifier");
			return (RET_ERR_INT);
		}
	}
	return (0);
}

int	check_first_char(char *str)
{
	if (!ft_isalpha(*str) && *str != '_')
	{
		print_err(1, str, "not a valid identifier");
		return (RET_ERR_INT);
	}
	return (0);
}

int	check_export_error(char *key, char *arg)
{
	int		is_err;

	is_err = check_first_char(key);
	is_err = check_key(key, arg);
	if (is_err == RET_ERR_INT)
		return (RET_ERR_INT);
	else
		return (0);
}
