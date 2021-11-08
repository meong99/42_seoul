#include "minishell.h"

static void	print_err_export(int err_num, char *arg, char *err_mag)
{
	errno = err_num;
	ft_putstr_fd("minishell: export: `", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd("': ", STDERR_FILENO);
	ft_putstr_fd(err_mag, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

static int	check_key(char *key, char *arg)
{
	while (*++key)
	{
		if (ft_isalnum(*key) == 0 && *key != '_')
		{
			print_err_export(1, arg, "not a valid identifier");
			return (RET_ERR_INT);
		}
	}
	return (0);
}

int	check_first_char(char *str)
{
	if (!ft_isalpha(*str) && *str != '_')
	{
		print_err_export(1, str, "not a valid identifier");
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
