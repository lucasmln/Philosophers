# include "./philosophers.h"

int			take_fork(t_all *all)
{
	pthread_mutex_lock(all->philo->f1);
	pthread_mutex_lock(all->philo->f2);
	writer(all, "has taken a fork");
	writer(all, "has taken a fork");
	return (1);
}

int			eat(t_all *all)
{
	writer(all, "is eating");
	usleep(all->data->time_eat * 1000);
	pthread_mutex_unlock(all->philo->f1);
	pthread_mutex_unlock(all->philo->f2);
	return (1);
}

int			sleeping(t_all *all)
{
	writer(all, "is sleeping");
	usleep(all->data->time_sleep * 1000);
	return (1);
}

int			thinking(t_all *all)
{
	writer(all, "is thinking");
	return (1);
}
