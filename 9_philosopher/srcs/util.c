#include "philo.h"

int	ret_timestamp(t_philo *philo)
{
	struct timeval	get_time;
	struct timeval	first_meal_time;
	int				timestamp;

	first_meal_time = philo->variable->first_meal_time;
	gettimeofday(&get_time, NULL);
	timestamp = get_time.tv_usec - first_meal_time.tv_usec + \
		(get_time.tv_sec - first_meal_time.tv_sec) * 1000000;
	return (timestamp);
}

int	print_status(t_philo *philo, char *str, int status)
{
	int	timestamp;

	pthread_mutex_lock(&philo->mutex->mutex_print);
	if (philo->variable->philo_alive == FALSE)
		return (RET_DEAD);
	timestamp = ret_timestamp(philo);
	printf("%d philo_%d %s\n", timestamp / 1000, philo->philo_number, str);
	pthread_mutex_unlock(&philo->mutex->mutex_print);
	if (status == STATUS_EAT)
	{
		philo->last_meal_time = timestamp;
		ft_usleep(philo, philo->variable->time_to_eat, timestamp);
	}
	if (status == STATUS_SLEEP)
		ft_usleep(philo, philo->variable->time_to_sleep, timestamp);
	return (RET_OK);
}

int	ft_usleep(t_philo *philo, int time, int timestamp)
{
	int	time_taken;

	time_taken = 0;
	while (time_taken <= timestamp + time * 1000)
		time_taken = ret_timestamp(philo);
	return (RET_OK);
}
