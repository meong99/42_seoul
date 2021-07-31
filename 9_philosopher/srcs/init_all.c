#include "philo.h"

void	init_varialbe(int ac, char **av, t_variable *variable)
{
	if (ac == 5)
		variable->must_eat = -1;
	else
		variable->must_eat = ft_atoi(av[5]);
	variable->num_of_philos = ft_atoi(av[1]);
	variable->time_to_die = ft_atoi(av[2]);
	variable->time_to_eat = ft_atoi(av[3]);
	variable->time_to_sleep = ft_atoi(av[4]);
	variable->finished_meal = 0;
	variable->philo_alive = TRUE;
	variable->first_meal_time.tv_sec = 0;
	variable->first_meal_time.tv_usec = 0;
}

int	init_mutex(t_mutex *mutex, t_variable *variable)
{
	int	i;

	i = -1;
	mutex->mutex_forks = malloc(sizeof(t_mutex) * variable->num_of_philos);
	if (mutex == NULL)
		return (RET_ERROR);
	while (++i < variable->num_of_philos)
		pthread_mutex_init(&mutex->mutex_forks[i], NULL);
	pthread_mutex_init(&mutex->mutex_print, NULL);
	pthread_mutex_init(&mutex->mutex_pause, NULL);
	pthread_mutex_lock(&mutex->mutex_pause);
	return (0);
}

t_philo	*init_philos(t_variable *variable, t_mutex *mutex)
{
	int	i;
	t_philo *philo;

	i = -1;
	philo = malloc(sizeof(t_philo) * \
		variable->num_of_philos);
	if (philo == NULL)
		return (NULL);
	while (++i < variable->num_of_philos)
	{
		philo[i].mutex = mutex;
		philo[i].variable = variable;
		philo[i].have_meal = 0;
		philo[i].fork_number[0] = i;
		if (i + 1 == variable->num_of_philos)
			philo[i].fork_number[1] = 0;
		else
			philo[i].fork_number[1] = i + 1;
	}
	return (philo);
}
