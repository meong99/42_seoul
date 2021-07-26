#include "philo.h"

static int	check_end_conditions(t_philo *philo)
{
	int	current_time;

	while (TRUE)
	{

	}
	return (0);
}

static int	create_thread(t_philo *philo, int num)
{
	int	i;

	if (num == ODD)
		i = 1;
	else
		i = 0;
	while (i < philo->variable->philo_nums)
	{
		philo[i].philo_number == i;
		pthread_create(&philo[i].philo_tid, NULL, \
			thread_philo, &philo[i]);
		i += 2;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int		i;
	t_philo	*philo;

	i = -1;
	if (error_check(ac, av) == RET_ERROR)
		return (RET_ERROR);
	if (init_all(ac, av, &philo) == RET_ERROR)
		return (RET_ERROR);
	create_thread(philo, ODD);
	usleep(philo->variable->time_to_eat);
	create_thread(philo, EVEN);
	check_end_conditions(philo);
	return (0);
}
