#include "philo.h"

int	get_current_time(t_philo *philo)
{
	struct timeval	get_time;
	long			current_time;

	gettimeofday(&get_time, NULL);
	if (philo->first_meal_time == 0)
		philo->first_meal_time = \
			get_time.tv_usec / 1000 + get_time.tv_sec * 1000;
	current_time = get_time.tv_usec / 1000 + get_time.tv_sec * 1000 - \
		philo->first_meal_time;
	return ((int)current_time);
}

int	print_status(t_philo *philo, char *str)
{
	int	current_time;

	pthread_mutex_lock(&philo->mutex->mutex_print);
	current_time = get_current_time(philo);
	if (philo->variable->philo_alive == FALSE)
		pthread_mutex_lock(&philo->mutex->mutex_pause);
	printf("%d philo_%d %s\n", current_time, philo->philo_number, str);
	philo->last_meal_time = current_time;
	pthread_mutex_unlock(&philo->mutex->mutex_print);
	return (0);
}

int	ft_usleep(int time)
{
	struct timeval	get_time;
	int				time_taken;
	int				start_time;

	time_taken = 0;
	gettimeofday(&get_time, NULL);
	start_time = get_time.tv_usec / 1000 + get_time.tv_sec * 1000;
	while (time_taken >= time)
	{
		usleep(time);
		gettimeofday(&get_time, NULL);
		time_taken = (get_time.tv_usec / 1000 + get_time.tv_sec * 1000) - \
			start_time;
	}
	return (0);
}
