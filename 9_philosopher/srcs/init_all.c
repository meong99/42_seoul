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
	pthread_mutex_init(&mutex->mutex_dead, NULL);
	pthread_mutex_lock(&mutex->mutex_dead);
}

static int	init_philos(t_main_struct *all_struct)
{
	int	i;

	i = -1;
	all_struct->philo = malloc(sizeof(t_philo) * all_struct->variable.philo_nums);
	if (all_struct->philo == NULL)
		return (RET_ERROR);
	while (++i < all_struct->variable.philo_nums)
	{
		all_struct->philo[i].philo_alive = TRUE;
		all_struct->philo[i].philo_forks[0] = FALSE;
		all_struct->philo[i].philo_forks[1] = FALSE;
		all_struct->philo[i].have_meal = 0;
		all_struct->philo[i].mutex = &all_struct->mutex;
		all_struct->philo[i].variable = &all_struct->variable;
	}
}

int	init_all(int ac, char **av, t_main_struct *all_struct)
{
	init_varialbe(ac, av, &all_struct->variable);
	if (init_mutex(&all_struct->mutex, &all_struct->variable) == RET_ERROR)
		return (RET_ERROR);
	if (init_philos(all_struct) == RET_ERROR)
		return (RET_ERROR);
}