#include "philo.h"

static void	philo_eat(t_philo *philo)
{
	int i;

	i = philo->philo_number;
	pthread_mutex_lock(&philo->mutex->mutex_forks[i - 1]);
	pthread_mutex_lock(&philo->mutex->mutex_forks[i]);
}

static void	philo_sleep(t_philo *philo)
{}

static void	philo_think(t_philo *philo)
{}

void	thread_philo(t_philo *philo)
{
	while (philo->have_meal != philo->variable->must_eat)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
}