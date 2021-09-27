#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>

# define RET_ERROR -1
# define TRUE 1
# define FALSE 0
# define ODD 1
# define EVEN 0
# define RET_OK 0
# define FINISHED_MEAL 2
# define RET_DEAD 3
# define RIGHT 0
# define LEFT 1
# define STATUS_EAT 0
# define STATUS_THINK 1
# define STATUS_SLEEP 2
# define STATUS_FORK 3
# define STATUS_END 4

typedef struct s_mutex
{
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	*mutex_forks;
}	t_mutex;

typedef struct s_variable
{
	size_t	start_time;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	int		must_eat;
	int		num_of_philos;
	int		finished_meal;
	int		philo_alive;
}	t_variable;

typedef struct s_philo
{
	int			fork_number[2];
	int			philo_number;
	int			have_meal;
	size_t		last_meal_time;
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
void	free_all(t_philo *philo, t_mutex *mutex, t_variable *variable);

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
size_t	ret_timestamp(void);
int		print_status(t_philo *philo, char *str, int status, int philo_num);
int		ft_usleep(size_t time, size_t timestamp);
int		ft_isdigit(int num);
int		ft_atoi(const char *str);

#endif