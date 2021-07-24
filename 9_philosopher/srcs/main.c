#include "philo.h"

int main(int ac, char **av)
{
	int	i;
	t_main_struct all_struct;

	i = -1;
	if (error_check(ac, av) == RET_ERROR)
		return (RET_ERROR);
	if (init_all(ac, av, &all_struct) == RET_ERROR)
		return (RET_ERROR);
	while (++i < all_struct.varialbe.philo_num)
	{
		pthread_create(&all_struct.philo[i].philo_tid, NULL, \
			thread_philo, &all_struct);
		pthread_detach(&all_struct.philo[i].philo_tid);
	}
	return (0);
}
