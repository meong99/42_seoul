#include "philo.h"

int	get_current_time(t_philo *philo)
{
	struct timeval	get_time;
	int				current_time;

	gettimeofday(&get_time, NULL);
	current_time = (int)(get_time.tv_usec / 1000) - \
		philo->variable.first_meal_time;
	return (current_time);
}

int	print_status(t_philo *philo, char *str, int status)
{
	int	current_time;

	pthread_mutex_lock(&philo->mutex.mutex_print);
	current_time = get_current_time(philo);
	if (philo->variable.philo_alive == FALSE)
		return (RET_ERROR);
	printf("%d philo_%d %s\n", current_time, philo->philo_number, str);
	if (status == STATUS_EAT)
		philo->last_meal_time = current_time;
	pthread_mutex_unlock(&philo->mutex.mutex_print);
	return (0);
}
