#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <time.h>
# include "libft.h"

# define RET_ERROR -1

typedef struct	s_philo
{
	int	philo_alive;
	int	philo_forks[2];
	int	philo_tid;
	time_t	philo_taken_time;
}	t_philo;

typedef struct	s_mutex
{
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	*mutex_fork;
}	t_mutex;

typedef struct	s_main_struct
{
	t_philo	*philo;
	t_mutex	mutex;
	time_t	first_meal_time;
}	t_main_struct;

int	error_check(int ac, char **av);
void	init_all(void);
void	free_all(void);
void	thread_philo(void);

#endif