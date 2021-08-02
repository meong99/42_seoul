#include "philo.h"

static int	parameter_num(int ac)
{
	if (ac != 5 && ac != 6)
	{
		printf("Error\n");
		printf("./philo [Numver_of_philosophers] ");
		printf("[Time_to_die] [Time_to_eat] [Time_to_sleep] ");
		printf("(Number_of_times_each_philosophers_must_eat)\n");
		return (RET_ERROR);
	}
	return (RET_OK);
}

static int	parameter_str(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (RET_ERROR);
		str++;
	}
	return (RET_OK);
}

int	invalid_param_check(t_variable *variable)
{
	if (variable->num_of_philos >= 200)
	{
		printf("Error\n");
		printf("The philosophers must be less than 200\n");
		return (RET_ERROR);
	}
	if (variable->time_to_die < 60 || variable->time_to_eat < 60 \
		|| variable->time_to_sleep < 60)
	{
		printf("Error\n");
		printf("\"time_to_die, time_to_eat, time_to_sleep\" ");
		printf("must be greater than or equal to 60 ms\n");
		return (RET_ERROR);
	}
	return (RET_OK);
}

int	error_check(int ac, char **av)
{
	int	i;

	i = 0;
	if (parameter_num(ac) == RET_ERROR)
		return (RET_ERROR);
	while (++i < ac)
	{
		if (parameter_str(av[i]) == RET_ERROR)
		{
			printf("Error\nparameters must be numeric\n");
			return (RET_ERROR);
		}
	}
	return (RET_OK);
}
