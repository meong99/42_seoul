#include "philo.h"

void	free_all(t_philo *philo, t_mutex *mutex, t_variable *variable)
{
	int	i;

	i = -1;
	while (++i < variable->num_of_philos)
		pthread_join(philo[i].philo_tid, NULL);
	i = -1;
	pthread_mutex_destroy(&mutex->mutex_print);
	while (++i < variable->num_of_philos)
		pthread_mutex_destroy(&mutex->mutex_forks[i]);
	free(mutex->mutex_forks);
	free(philo);
}
