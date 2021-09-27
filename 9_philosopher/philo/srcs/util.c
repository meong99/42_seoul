#include "philo.h"

size_t	ret_timestamp(void)
{
	struct timeval	get_time;
	size_t			timestamp;

	gettimeofday(&get_time, NULL);
	timestamp = get_time.tv_sec * 1000 + get_time.tv_usec / 1000;
	return (timestamp);
}

int	print_status(t_philo *philo, char *str, int status, int philo_number)
{
	size_t	timestamp;

	if (!pthread_mutex_lock(&philo->mutex->mutex_print) && \
		status != STATUS_END && philo->variable->philo_alive == FALSE)
		return (RET_DEAD);
	timestamp = ret_timestamp();
	printf("%zu philo_%d %s\n", \
		timestamp - philo->variable->start_time, philo_number, str);
	pthread_mutex_unlock(&philo->mutex->mutex_print);
	if (status == STATUS_EAT)
	{
		philo->last_meal_time = timestamp;
		ft_usleep(philo->variable->time_to_eat, timestamp);
	}
	if (status == STATUS_SLEEP)
		ft_usleep(philo->variable->time_to_sleep, timestamp);
	return (RET_OK);
}

int	ft_usleep(size_t time, size_t timestamp)
{
	size_t			time_taken;

	time_taken = 0;
	while (time_taken <= time)
	{
		time_taken = ret_timestamp() - timestamp;
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
