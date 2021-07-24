#include "philo.h"

static void	init_varialbe(int ac, char **av, t_varialbe *varialbe)
{
	if (ac == 5)
		varialbe->must_eat = 0;
	else
		varialbe->must_eat = ft_atoi(av[5]);
	varialbe->philo_num = ft_atoi(av[0]);
	varialbe->time_to_die = ft_atoi(av[1]);
	varialbe->time_to_eat = ft_atoi(av[2]);
	varialbe->time_to_sleep = ft_atoi(av[3]);
}

static int	init_mutex(t_mutex *mutex, t_varialbe *varialbe)
{
	int	i;

	i = -1;
	mutex->mutex_fork = malloc(sizeof(t_mutex) * varialbe->philo_num);
	if (mutex == NULL)
		return (RET_ERROR);
	while (++i < varialbe->philo_num)
		pthread_mutex_init(&mutex->mutex_fork[i], NULL);
	pthread_mutex_init(&mutex->mutex_print, NULL);
}

static int	init_philos(t_philo *philo, t_varialbe *varialbe)
{
	philo = malloc(sizeof(t_philo) * varialbe->philo_num);
	if (philo == NULL)
		return (RET_ERROR);
	philo->philo_alive = TRUE;
	philo->philo_forks[0] = FALSE;
	philo->philo_forks[1] = FALSE;
}

int	init_all(int ac, char **av, t_main_struct *all_struct)
{
	init_varialbe(ac, av, &all_struct->varialbe);
	if (init_mutex(&all_struct->mutex, &all_struct->varialbe) == RET_ERROR)
		return (RET_ERROR);
	if (init_philos(&all_struct->philo, &all_struct->varialbe) == RET_ERROR)
		return (RET_ERROR);
}