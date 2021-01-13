# include "./philosophers.h"

void	*routine(void *arg)
{
	t_all		*all;
	int			i;
	pthread_t	check;

	all = (t_all *)arg;
	i = -1;
	pthread_mutex_lock(all->philo->locker);
	i = 0;
	while (all->data->die == false && all->data->all_meals == false)
	{
		pthread_detach(check);
		pthread_create(&check, NULL, &checker, all);
		take_fork(all);
		check_death(all);
		eat(all);
		check_death(all);
		writer(all, "is sleeping");
		usleep(all->data->time_sleep * 1000);
		check_death(all);
		writer(all, "is thinking");
		i++;
		if (all->data->round > 0 && i >= all->data->round)
			all->data->all_meals = true;
	}
	i = -1;
	pthread_mutex_unlock(all->philo->locker);
	return (NULL);
}

void		*checker(void *arg)
{
	t_all			*all;
	unsigned int	now;

	all = (t_all *)arg;
	usleep(all->data->time_death * 1000);
	now = get_time(all->data->time);
	if (now - all->philo->last_time_eat >= (unsigned int)all->data->time_death)
	{
		output_die(all, "is dead");
		all->data->die = true;
	}
	return (NULL);
}

int			check_death(t_all *all)
{
	if (all->data->time_death <= (int)get_time(all->data->time) - all->philo->last_time_eat)
	{
		all->data->die = true;
		output_die(all, "is die");
		return (1);
	}
	return (0);
}

int			take_fork(t_all *all)
{
	pthread_mutex_lock(all->philo->f1);
	pthread_mutex_lock(all->philo->f2);
	check_death(all);
	writer(all, "has taken a fork");
	writer(all, "has taken a fork");
	return (1);
}

int			eat(t_all *all)
{
	writer(all, "is eating");
	usleep(all->data->time_eat * 1000);
	all->philo->last_time_eat = get_time(all->data->time);
	pthread_mutex_unlock(all->philo->f1);
	pthread_mutex_unlock(all->philo->f2);
	return (1);
}
