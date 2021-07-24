#include "philo.h"

static int	save_time(t_philo *philo)
{
	if (philo->variable->first_meal_time.tv_usec == NULL)
		gettimeofday(NULL, NULL);
}

static void	philo_eat(t_philo *philo)
{
	int	i;

	i = philo->philo_number;
	pthread_mutex_lock(&philo->mutex->mutex_forks[i - 1]);
	pthread_mutex_lock(&philo->mutex->mutex_forks[i]);
	if (philo->philo_alive == NULL)
		pthread_mutex_lock(&philo->mutex->mutex_dead);
	save_time(philo);
}

static void	philo_sleep(t_philo *philo)
{
	philo = 0;
}

static void	philo_think(t_philo *philo)
{
	philo = 0;
}

void	thread_philo(t_philo *philo)
{
	while (philo->have_meal != philo->variable->must_eat)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
}
