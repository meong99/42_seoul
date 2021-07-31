#include "philo.h"

static int	philo_eat(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->mutex->mutex_forks[philo->fork_number[0]]) \
		!= RET_OK)
		pthread_mutex_lock(&philo->mutex->mutex_pause);
	print_status(philo, "has taken a fork");
	if (pthread_mutex_lock(&philo->mutex->mutex_forks[philo->fork_number[1]]) \
		!= RET_OK)
		pthread_mutex_lock(&philo->mutex->mutex_pause);
	print_status(philo, "has taken a fork");
	print_status(philo, "is eating");
	ft_usleep(philo, philo->variable->time_to_eat);
	pthread_mutex_unlock(&philo->mutex->mutex_forks[philo->fork_number[0]]);
	pthread_mutex_unlock(&philo->mutex->mutex_forks[philo->fork_number[1]]);
	philo->have_meal++;
	if (philo->have_meal == philo->variable->must_eat)
		philo->variable->finished_meal++;
	return (0);
}

static int	philo_sleep(t_philo *philo)
{
	int	timestamp;

	pthread_mutex_lock(&philo->mutex->mutex_print);
	timestamp = ret_timestamp(philo);
	printf("%d philo_%d is sleeping\n", timestamp / 1000, philo->philo_number);
	pthread_mutex_unlock(&philo->mutex->mutex_print);
	ft_usleep(philo, philo->variable->time_to_sleep);
	return (0);
}

void	*thread_philo(void *start_routine)
{
	t_philo	*philo;

	philo = (t_philo *)start_routine;
	if (philo->variable->first_meal_time.tv_sec == 0)
		gettimeofday(&philo->variable->first_meal_time, NULL);
	while (TRUE)
	{
		philo_eat(philo);
		if (philo->have_meal == philo->variable->must_eat)
			pthread_mutex_lock(&philo->mutex->mutex_pause);
		philo_sleep(philo);
		print_status(philo, "is thinking");
	}
	return (0);
}
