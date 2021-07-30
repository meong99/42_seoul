#include "philo.h"

static int	philo_eat(t_philo *philo)
{
	int	i;

	i = philo->philo_number;
	pthread_mutex_lock(&philo->mutex->mutex_forks[i - 1]);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(&philo->mutex->mutex_forks[i]);
	print_status(philo, "has taken a fork");
	print_status(philo, "is eating");
	ft_usleep(philo->variable->time_to_eat);
	pthread_mutex_unlock(&philo->mutex->mutex_forks[i - 1]);
	pthread_mutex_unlock(&philo->mutex->mutex_forks[i]);
	philo->have_meal++;
	if (philo->have_meal == philo->variable->must_eat)
	{
		philo->variable->finished_meal++;
		pthread_mutex_lock(&philo->mutex->mutex_pause);
	}
	return (0);
}

static int	philo_sleep(t_philo *philo)
{
	int	current_time;

	pthread_mutex_lock(&philo->mutex->mutex_print);
	current_time = get_current_time(philo);
	printf("%d philo_%d is sleeping\n", current_time, philo->philo_number);
	pthread_mutex_unlock(&philo->mutex->mutex_print);
	ft_usleep(philo->variable->time_to_sleep);
	return (0);
}

void	*thread_philo(void *start_routine)
{
	t_philo *philo;

	philo = (t_philo *)start_routine;
	while (philo->have_meal != philo->variable->must_eat)
	{
		philo_eat(philo);
		philo_sleep(philo);
		print_status(philo, "is thinking");
	}
	return (0);
}
