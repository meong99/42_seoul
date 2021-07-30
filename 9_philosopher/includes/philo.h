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

typedef struct s_mutex
{
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	*mutex_forks;
	pthread_mutex_t	mutex_pause;
}	t_mutex;

typedef struct s_variable
{
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		must_eat;
	int		num_of_philos;
	int		finished_meal;
	int		philo_alive;
	long	first_meal_time;
}	t_variable;

typedef struct s_philo
{
	int			last_meal_time;
	int			philo_number;
	int			have_meal;
	pthread_t	philo_tid;
	t_mutex		*mutex;
	t_variable	*variable;
}	t_philo;
/*
** error_check.c
*/
int		error_check(int ac, char **av);

/*
** free_all.c 
*/
void	free_all(void);

/*
**  init_all.c
*/
void	init_varialbe(int ac, char **av, t_variable *variable);
int		init_mutex(t_mutex *mutex, t_variable *variable);
t_philo	*init_philos(t_variable *variable, t_mutex *mutex);

/*
** thread_philo.c 
*/
void	*thread_philo(void *start_routine);

/*
** util.c 
*/
int		get_current_time(t_philo *philo);
int		print_status(t_philo *philo, char *str);
int		ft_usleep(int time);
#endif