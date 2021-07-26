#include "philo.h"

static void	init_varialbe(int ac, char **av, t_variable *variable)
{
	if (ac == 5)
		variable->must_eat = -1;
	else
		variable->must_eat = ft_atoi(av[5]);
	variable->philo_nums = ft_atoi(av[0]);
	variable->time_to_die = ft_atoi(av[1]);
	variable->time_to_eat = ft_atoi(av[2]);
	variable->time_to_sleep = ft_atoi(av[3]);
	variable->num_finished_meal = 0;
}

static int	init_mutex(t_mutex *mutex, t_variable *variable)
{
	int	i;

	i = -1;
	mutex->mutex_forks = malloc(sizeof(t_mutex) * variable->philo_nums);
	if (mutex == NULL)
		return (RET_ERROR);
	while (++i < variable->philo_nums)
		pthread_mutex_init(&mutex->mutex_forks[i], NULL);
	pthread_mutex_init(&mutex->mutex_print, NULL);
	pthread_mutex_init(&mutex->mutex_pause, NULL);
	pthread_mutex_lock(&mutex->mutex_pause);
}

static int	init_philos(t_philo *philo)
{
	int	i;

	i = -1;
	if (philo == NULL)
		return (RET_ERROR);
	while (++i < philo->variable->philo_nums)
	{
		philo[i].philo_alive = TRUE;
		philo[i].philo_forks[0] = FALSE;
		philo[i].philo_forks[1] = FALSE;
		philo[i].have_meal = 0;
		philo[i].mutex = &philo->mutex;
		philo[i].variable = &philo->variable;
	}
	philo[0].variable->first_meal_time = 0;
}

int	init_all(int ac, char **av, t_philo **philo)
{
	*philo = malloc(sizeof(t_philo) * \
		(*philo)->variable->philo_nums);
	init_varialbe(ac, av, &(*philo)->variable);
	if (init_mutex(&(*philo)->mutex, &(*philo)->variable) == RET_ERROR)
		return (RET_ERROR);
	if (init_philos(philo) == RET_ERROR)
		return (RET_ERROR);
}
