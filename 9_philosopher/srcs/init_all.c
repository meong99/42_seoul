#include "philo.h"

static void	init_varialbe(int ac, char **av, t_variable *variable)
{
	if (ac == 5)
		variable->must_eat = -1;
	else
		variable->must_eat = ft_atoi(av[5]);
	variable->num_of_philos = ft_atoi(av[0]);
	variable->time_to_die = ft_atoi(av[1]);
	variable->time_to_eat = ft_atoi(av[2]);
	variable->time_to_sleep = ft_atoi(av[3]);
	variable->finished_meal = 0;
}

static int	init_mutex(t_mutex *mutex, t_variable *variable)
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

static int	init_philos(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->variable.num_of_philos)
	{
		philo[i].philo_forks[0] = FALSE;
		philo[i].philo_forks[1] = FALSE;
		philo[i].have_meal = 0;
	}
	philo->variable.philo_alive = TRUE;
	philo[0].variable.first_meal_time = 0;
	return (0);
}

int	init_all(int ac, char **av, t_philo **philo)
{
	*philo = malloc(sizeof(t_philo) * \
		(*philo)->variable.num_of_philos);
	if (philo == NULL)
		return (RET_ERROR);
	init_varialbe(ac, av, &(*philo)->variable);
	if (init_mutex(&(*philo)->mutex, &(*philo)->variable) == RET_ERROR)
		return (RET_ERROR);
	if (init_philos(*philo) == RET_ERROR)
		return (RET_ERROR);
	return (0);
}
