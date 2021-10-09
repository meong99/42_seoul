#include "minishell.h"

static void	print_err_unset(int err_num, char *arg, char *err_mag)
{
	errno = err_num;
	write(2, "minishell: unset: `", 19);
	write(2, arg, ft_strlen(arg));
	write(2, "': ", 3);
	write(2, err_mag, ft_strlen(err_mag));
	write(2, "\n", 1);
}

int	check_unset_error(char *key)
{
	int		is_err;

	is_err = 0;
	if (!ft_isalpha(*key) && *key != '_' && ++is_err)
		print_err_unset(1, key, "not a valid identifier");
	while (*++key)
	{
		if (ft_isalnum(*key) == 0 && *key != '_' && ++is_err)
			print_err_unset(1, key, "not a valid identifier");
	}
	if (is_err == true)
		return (RET_ERR_INT);
	else
		return (0);
}
