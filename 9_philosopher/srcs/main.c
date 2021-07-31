#include "philo.h"

static int	check_end_conditions(t_philo *philo, t_variable *variable)
{
	int	timestamp;
	int	i;

	while (variable->finished_meal != variable->must_eat)
	{
		i = -1;
		while (++i < variable->num_of_philos)
		{
			timestamp = ret_timestamp(philo);
			if ((timestamp - philo[i].last_meal_time) / 1000 >= \
				variable->time_to_die)
			{
				variable->philo_alive = FALSE;
				printf("%d philo_%d died\n", timestamp / 1000, i);
				return (0);
			}
		}
	}
	printf("Finished eating\n");
	return (0);
}

static int	create_thread(t_philo *philo, int num, int num_of_philos)
{
	int	i;

	if (num == ODD)
		i = 1;
	else
		i = 0;
	while (i < num_of_philos)
	{
		philo[i].philo_number = i;
		pthread_create(&philo[i].philo_tid, NULL, \
			thread_philo, &philo[i]);
		i += 2;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int			i;
	t_philo		*philo;
	t_variable	variable;
	t_mutex		mutex;

	i = -1;
	if (error_check(ac, av) == RET_ERROR)
		return (RET_ERROR);
	init_varialbe(ac, av, &variable);
	init_mutex(&mutex, &variable);
	philo = init_philos(&variable, &mutex);
	if (philo == NULL)
		return (0);
	create_thread(philo, ODD, variable.num_of_philos);
	usleep(variable.time_to_eat);
	create_thread(philo, EVEN, variable.num_of_philos);
	check_end_conditions(philo, &variable);
	return (0);
}
