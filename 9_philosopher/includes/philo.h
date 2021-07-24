#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <time.h>
# include "libft.h"

# define RET_ERROR -1
# define TRUE 1
# define FALSE 0
# define ODD 1
# define EVEN 0

typedef struct	s_philo
{
	int	philo_alive;
	int	philo_forks[2];
	pthread_t	philo_tid;
	time_t	last_meal_time;
	int	philo_number;
	int	have_meal;
	t_mutex	*mutex;
	t_variable	*variable;
}	t_philo;

typedef struct	s_mutex
{
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	*mutex_forks;
	pthread_mutex_t	mutex_dead;
}	t_mutex;

typedef struct	s_variable
{
	time_t	first_meal_time;
	time_t	time_to_die;
	time_t	time_to_eat;
	time_t	time_to_sleep;
	int	must_eat;
	int	philo_nums;
}	t_variable;

typedef struct	s_main_struct
{
	t_philo	*philo;
	t_mutex	mutex;
	t_variable	variable;
}	t_main_struct;

int	error_check(int ac, char **av);
int	init_all(int ac, char **av, t_main_struct *all_struct);
void	free_all(void);
void	thread_philo(t_philo *philo);

#endif