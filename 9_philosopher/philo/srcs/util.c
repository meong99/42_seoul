#include "philo.h"

int	ret_timestamp(t_philo *philo)
{
	struct timeval	get_time;
	struct timeval	first_meal;
	int				timestamp;

	first_meal = philo->variable->first_meal_time;
	if (first_meal.tv_sec == 0)
		return (0);
	gettimeofday(&get_time, NULL);
	timestamp = (get_time.tv_sec * 1000000 + get_time.tv_usec) - \
		(first_meal.tv_sec * 1000000 + first_meal.tv_usec);
	return (timestamp);
}

int	print_status(t_philo *philo, char *str, int status, int philo_number)
{
	int	timestamp;

	pthread_mutex_lock(&philo->mutex->mutex_print);
	if (status != STATUS_END && philo->variable->philo_alive == FALSE)
		return (RET_DEAD);
	timestamp = ret_timestamp(philo);
	printf("%d philo_%d %s\n", timestamp / 1000, philo_number, str);
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
	{
		time_taken = ret_timestamp(philo);
		usleep(time);
	}
	return (RET_OK);
}

int	ft_isdigit(int num)
{
	if (num >= '0' && num <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	unsigned int	result;
	int				sign;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *str++ - '0';
	}
	return (result * sign);
}
