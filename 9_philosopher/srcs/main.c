#include "philo.h"

static int	check_end_conditions(t_philo *philo, t_variable *variable)
{
	int	timestamp;
	int	i;

	i = -1;
	while (++i < variable->num_of_philos)
	{
		timestamp = ret_timestamp(philo);
		if ((timestamp - philo[i].last_meal_time) / 1000 >= \
			variable->time_to_die)
		{
			variable->philo_alive = FALSE;
			printf("%d philo_%d died\n", timestamp / 1000, i);
			free_all(philo, philo->mutex, philo->variable);
			return (RET_OK);
		}
		else if (variable->finished_meal == variable->num_of_philos)
		{
			printf("%d End of meal\n", timestamp / 1000);
			free_all(philo, philo->mutex, philo->variable);
			return (RET_OK);
		}
		if (i == variable->num_of_philos - 1)
			i = -1;
	}
	return (RET_OK);
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
	return (RET_OK);
}

static int	sleep_until_even_eat(t_variable variable)
{
	struct timeval	get_time;
	struct timeval	timestamp;

	gettimeofday(&get_time, NULL);
	while (TRUE)
	{
		gettimeofday(&timestamp, NULL);
		if ((get_time.tv_usec - timestamp.tv_usec + \
			(get_time.tv_sec - timestamp.tv_sec) * 1000000) > \
			variable.time_to_eat * 900)
			break ;
	}
	return (RET_OK);
}

int	main(int ac, char **av)
{
	int				i;
	t_philo			*philo;
	t_variable		variable;
	t_mutex			mutex;

	i = -1;
	if (error_check(ac, av) == RET_ERROR)
		return (RET_ERROR);
	init_varialbe(ac, av, &variable);
	if (invalid_param_check(&variable) == RET_ERROR)
		return (RET_ERROR);
	init_mutex(&mutex, &variable);
	philo = init_philos(&variable, &mutex);
	if (philo == NULL)
		return (RET_ERROR);
	create_thread(philo, EVEN, variable.num_of_philos);
	sleep_until_even_eat(variable);
	create_thread(philo, ODD, variable.num_of_philos);
	check_end_conditions(philo, &variable);
	return (RET_OK);
}
