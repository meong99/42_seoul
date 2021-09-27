#include "philo.h"

static int	check_end_conditions(t_philo *philo, t_variable *variable)
{
	size_t	timestamp;
	int	i;

	i = -1;
	while (++i < variable->num_of_philos)
	{
		timestamp = ret_timestamp();
		if (timestamp - philo[i].last_meal_time >= \
			variable->time_to_die && philo[i].last_meal_time)
		{
			variable->philo_alive = FALSE;
			print_status(philo, "died", STATUS_END, i + 1);
			break ;
		}
		else if (variable->finished_meal == variable->num_of_philos)
		{
			print_status(philo, "End of meal", STATUS_END, i + 1);
			break ;
		}
		if (i == variable->num_of_philos - 1)
			i = -1;
	}
	free_all(philo, philo->mutex, philo->variable);
	return (RET_OK);
}

static int	create_thread(t_philo *philo, int num, int num_of_philos)
{
	int	i;

	if (num == ODD)
		i = 0;
	else
		i = 1;
	while (i < num_of_philos)
	{
		philo[i].philo_number = i;
		pthread_create(&philo[i].philo_tid, NULL, \
			thread_philo, &philo[i]);
		i += 2;
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
	init_mutex(&mutex, &variable);
	philo = init_philos(&variable, &mutex);
	if (philo == NULL)
		return (RET_ERROR);
	create_thread(philo, EVEN, variable.num_of_philos);
	ft_usleep(philo->variable->time_to_eat, ret_timestamp());
	create_thread(philo, ODD, variable.num_of_philos);
	check_end_conditions(philo, &variable);
	return (RET_OK);
}
