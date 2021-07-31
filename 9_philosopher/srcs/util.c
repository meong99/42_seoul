#include "philo.h"

int	ret_timestamp(t_philo *philo)
{
	struct timeval	get_time;
	struct timeval	first_meal_time;
	int 			timestamp;

	first_meal_time = philo->variable->first_meal_time;
	gettimeofday(&get_time, NULL);
	timestamp = get_time.tv_usec - first_meal_time.tv_usec + \
		(get_time.tv_sec - first_meal_time.tv_sec) * 1000000;
	return (timestamp);
}

int	print_status(t_philo *philo, char *str)
{
	int	current_time;

	pthread_mutex_lock(&philo->mutex->mutex_print);
	current_time = ret_timestamp(philo);
	if (philo->variable->philo_alive == FALSE)
		pthread_mutex_lock(&philo->mutex->mutex_pause);
	printf("%d philo_%d %s\n", current_time / 1000, philo->philo_number, str);
	philo->last_meal_time = current_time;
	pthread_mutex_unlock(&philo->mutex->mutex_print);
	return (0);
}

int	ft_usleep(t_philo *philo, int time)
{
	int				time_taken;

	time_taken = 0;
	while (time_taken <= philo->last_meal_time + time * 1000)
	{
		usleep(time);
		time_taken = ret_timestamp(philo);
	}
	return (0);
}
