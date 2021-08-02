#include "philo.h"

static int	philo_eat(t_philo *philo)
{
	if (pthread_mutex_lock(\
		&philo->mutex->mutex_forks[philo->fork_number[RIGHT]]) != RET_OK)
		return (RET_ERROR);
	if (print_status(philo, "has taken a fork") == RET_DEAD)
		return (RET_DEAD);
	if (pthread_mutex_lock(\
		&philo->mutex->mutex_forks[philo->fork_number[LEFT]]) != RET_OK)
		return (RET_ERROR);
	if (print_status(philo, "has taken a fork") == RET_DEAD)
		return (RET_DEAD);
	if (print_status(philo, "is eating") == RET_DEAD)
		return (RET_DEAD);
	ft_usleep(philo, philo->variable->time_to_eat);
	pthread_mutex_unlock(&philo->mutex->mutex_forks[philo->fork_number[RIGHT]]);
	pthread_mutex_unlock(&philo->mutex->mutex_forks[philo->fork_number[LEFT]]);
	philo->have_meal++;
	if (philo->have_meal == philo->variable->must_eat)
	{
		philo->variable->finished_meal++;
		return (FINISHED_MEAL);
	}
	return (RET_OK);
}

static int	philo_sleep(t_philo *philo)
{
	int	timestamp;

	pthread_mutex_lock(&philo->mutex->mutex_print);
	timestamp = ret_timestamp(philo);
	if (philo->variable->philo_alive == FALSE)
		return (RET_DEAD);
	printf("%d philo_%d is sleeping\n", timestamp / 1000, philo->philo_number);
	pthread_mutex_unlock(&philo->mutex->mutex_print);
	ft_usleep(philo, philo->variable->time_to_sleep);
	return (RET_OK);
}

void	*thread_philo(void *start_routine)
{
	t_philo	*philo;

	philo = (t_philo *)start_routine;
	if (philo->variable->first_meal_time.tv_sec == 0)
		gettimeofday(&philo->variable->first_meal_time, NULL);
	while (TRUE)
	{
		if (philo_eat(philo) != RET_OK)
			return (NULL);
		if (philo_sleep(philo) != RET_OK)
			return (NULL);
		if (philo->variable->philo_alive == FALSE)
			return (NULL);
		print_status(philo, "is thinking");
	}
	return (0);
}
