#include "philo.h"

int main(int ac, char **av)
{
	t_main_struct all_struct;

	if (error_check(ac, av) == RET_ERROR)
		return (RET_ERROR);
	init_all(ac, av, &all_struct);
	return (0);
}
