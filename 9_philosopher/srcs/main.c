#include "philo.h"

static int	check_end_conditions(t_main_struct *all_struct)
{

}

int main(int ac, char **av)
{
	int	i;
	t_main_struct all_struct;

	i = -1;
	if (error_check(ac, av) == RET_ERROR)
		return (RET_ERROR);
	if (init_all(ac, av, &all_struct) == RET_ERROR)
		return (RET_ERROR);
	while (++i < all_struct.variable.philo_nums)
	{
		all_struct.philo[i].philo_number == i;
		pthread_create(&all_struct.philo[i].philo_tid, NULL, \
			thread_philo, &all_struct.philo[i]);
		pthread_detach(&all_struct.philo[i].philo_tid);
	}
	check_end_conditions(&all_struct);
	return (0);
}
