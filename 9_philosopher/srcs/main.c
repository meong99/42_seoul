#include "philo.h"

static int	check_end_conditions(t_philo *philo, t_variable *variable)
{
	int	current_time;
	int	i;

	while (variable->finished_meal < variable->must_eat)
	{
		i = -1;
		while (++i < variable->num_of_philos)
		{
			current_time = get_current_time(philo);
			if (current_time - philo[i].last_meal_time >= \
				variable->time_to_die)
			{
				variable->philo_alive = FALSE;
				printf("%d philo_%d died\n", current_time, i);
				return (0);
			}
		}
	}
	printf("Finished eating\n");
	return (0);
}

static int	create_thread(t_philo *philo, int num)
{
	int	i;

	if (num == ODD)
		i = 1;
	else
		i = 0;
	while (i < philo->variable.num_of_philos)
	{
		philo[i].philo_number = i;
		pthread_create(&philo[i].philo_tid, NULL, \
			thread_philo, philo + i);
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
	usleep(philo->variable.time_to_eat * 500);
	create_thread(philo, EVEN);
	check_end_conditions(philo, &philo->variable);
	return (0);
}
