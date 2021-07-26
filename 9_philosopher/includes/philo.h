#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include "libft.h"

# define RET_ERROR -1
# define TRUE 1
# define FALSE 0
# define ODD 1
# define EVEN 0
# define STATUS_EAT 0
# define STATUS_SLEEP 1
# define STATUS_THINK 2
# define STATUS_DEAD 3
# define STATUS_FORKS 4

typedef struct s_philo
{
	int			philo_alive;
	int			philo_forks[2];
	pthread_t	philo_tid;
	int			last_meal_time;
	int			philo_number;
	int			have_meal;
	t_mutex		*mutex;
	t_variable	*variable;
}	t_philo;

typedef struct s_mutex
{
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	*mutex_forks;
	pthread_mutex_t	mutex_pause;
}	t_mutex;

typedef struct s_variable
{
	int	first_meal_time;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat;
	int	philo_nums;
	int	num_finished_meal;
}	t_variable;

int		error_check(int ac, char **av);
int		init_all(int ac, char **av, t_philo **philo);
void	free_all(void);
void	thread_philo(t_philo *philo);
int		get_current_time(t_philo *philo);
int		print_status(t_philo *philo, char *str, int status);

#endif