#include "philo.h"

int	get_current_time(t_philo *philo)
{
	struct timeval	get_time;
	int 			current_time;

	gettimeofday(&get_time, NULL);
	if (philo->variable->first_meal_time == 0)
		philo->variable->first_meal_time = \
			get_time.tv_usec / 1000 + get_time.tv_sec * 1000;
	current_time = get_time.tv_usec / 1000 + get_time.tv_sec * 1000 - \
		philo->variable->first_meal_time;
	return (current_time);
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

int	ft_usleep(t_philo *philo, int time)
{
	struct timeval	get_time;
	struct timeval	start_time;
	int				time_taken;

	time_taken = 0;
	philo = 0;
	gettimeofday(&start_time, NULL);
	while (time_taken <= time)
	{
		usleep(10);
		gettimeofday(&get_time, NULL);
		time_taken = (get_time.tv_usec - start_time.tv_usec + \
		(get_time.tv_sec - start_time.tv_sec) * 1000000) / 1000;
	}
	return (0);
}
