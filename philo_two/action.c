# include "./philosophers.h"

void	*routine(void *arg)
{
	t_all	*all;
	int		i;

	all = (t_all *)arg;
	i = 0;
	while (all->data->die == false && all->data->all_meals == false)
	{
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
	sem_wait(all->data->fork);
	sem_wait(all->data->fork);
	check_death(all);
	writer(all, "has taken a fork");
	writer(all, "has taken a fork");
	return (1);
}

int			eat(t_all *all)
{
	writer(all, "is eating");
	all->philo->last_time_eat = get_time(all->data->time);
	usleep(all->data->time_eat * 1000);
	sem_post(all->data->fork);
	sem_post(all->data->fork);
	return (1);
}
