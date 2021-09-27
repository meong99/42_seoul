#include "philo.h"

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
