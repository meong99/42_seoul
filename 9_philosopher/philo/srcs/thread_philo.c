#include "philo.h"

static int	philo_eat(t_philo *philo)
{
	if (pthread_mutex_lock(\
		&philo->mutex->mutex_forks[philo->fork_number[LEFT]]) != RET_OK)
		return (RET_ERROR);
	if (print_status(philo, "has taken a fork", STATUS_FORK, \
		philo->philo_number + 1) == RET_DEAD)
		return (RET_DEAD);
	if (pthread_mutex_lock(\
		&philo->mutex->mutex_forks[philo->fork_number[RIGHT]]) != RET_OK)
		return (RET_ERROR);
	if (print_status(philo, "has taken a fork", STATUS_FORK, \
		philo->philo_number + 1) == RET_DEAD)
		return (RET_DEAD);
	if (print_status(philo, "is eating", STATUS_EAT, \
		philo->philo_number + 1) == RET_DEAD)
		return (RET_DEAD);
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

void	*thread_philo(void *start_routine)
{
	t_philo	*philo;

	philo = (t_philo *)start_routine;
	sleep(1);
	if (philo->variable->first_meal_time.tv_sec == 0)
		gettimeofday(&philo->variable->first_meal_time, NULL);
	while (philo->variable->philo_alive == TRUE)
	{
		if (philo_eat(philo) != RET_OK)
			break ;
		if (print_status(philo, "is sleeping", STATUS_SLEEP, \
			philo->philo_number + 1) != RET_OK)
			break ;
		if (print_status(philo, "is thinking", STATUS_THINK, \
			philo->philo_number + 1) != RET_OK)
			break ;
	}
	pthread_mutex_unlock(&philo->mutex->mutex_print);
	pthread_mutex_unlock(&philo->mutex->mutex_forks[philo->fork_number[RIGHT]]);
	pthread_mutex_unlock(&philo->mutex->mutex_forks[philo->fork_number[LEFT]]);
	return (RET_OK);
}
