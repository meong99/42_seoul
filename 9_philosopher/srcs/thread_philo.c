#include "philo.h"

static int	philo_eat(t_philo *philo)
{
	int	i;
	int	current_time;

	i = philo->philo_number;
	pthread_mutex_lock(&philo->mutex->mutex_forks[i - 1]);
	if (print_status(philo, "has taken a fork", STATUS_FORKS) == RET_ERROR)
		return (RET_ERROR);
	pthread_mutex_lock(&philo->mutex->mutex_forks[i]);
	if (print_status(philo, "has taken a fork", STATUS_FORKS) == RET_ERROR)
		return (RET_ERROR);
	if (print_status(philo, "is eating", STATUS_EAT) == RET_ERROR)
		return (RET_ERROR);
	usleep(philo->variable->time_to_eat);
	philo->have_meal++;
	return (0);
}

static int	philo_sleep(t_philo *philo)
{
	print_status(philo, "is sleeping", STATUS_SLEEP);
	usleep(philo->variable->time_to_sleep * 1000);
	return (0);
}

static int	philo_think(t_philo *philo)
{
	print_status(philo, "is thinking", STATUS_THINK);
	return (0);
}

void	thread_philo(t_philo *philo)
{
	while (philo->have_meal != philo->variable->must_eat)
	{
		if (philo_eat(philo) == RET_ERROR)
			return (RET_ERROR);
		if (philo_sleep(philo) == RET_ERROR)
			return (RET_ERROR);
		if (philo_think(philo) == RET_ERROR)
			return (RET_ERROR);
	}
	return (0);
}
