#include "philo.h"

static int	check_end_conditions(t_main_struct *all_struct)
{
	all_struct = 0;
	return (0);
}

static int	create_thread(t_main_struct *all_struct, int num)
{
	int	i;

	if (num == ODD)
		i = 1;
	else
		i = 0;
	while (i < all_struct->variable.philo_nums)
	{
		all_struct->philo[i].philo_number == i;
		pthread_create(&all_struct->philo[i].philo_tid, NULL, \
			thread_philo, &all_struct->philo[i]);
		i += 2;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int				i;
	t_main_struct	all_struct;

	i = -1;
	if (error_check(ac, av) == RET_ERROR)
		return (RET_ERROR);
	if (init_all(ac, av, &all_struct) == RET_ERROR)
		return (RET_ERROR);
	create_thread(&all_struct, ODD);
	usleep(all_struct.variable.time_to_eat);
	create_thread(&all_struct, EVEN);
	check_end_conditions(&all_struct);
	return (0);
}
