#include "./philosophers.h"

void	*routine(void *arg)
{
	t_all	*all;
	int		i;

	i = -1;
	all = (t_all *)arg;
//	if (all->philo->idx < all->data->nb_philo)
//		usleep(70);
	while (all->data->die == false && ++i < all->data->round)
	{
		take_fork(all);
		eat(all);
		sleeping(all);
		thinking(all);
	}
	return (NULL);
}

void	philo_delete(t_philo *philo, t_data *data)
{
	int		i;

	i = -1;
	while (++i < data->nb_philo)
	{
		pthread_mutex_lock(philo[i].f1);
		pthread_mutex_destroy(philo[i].f1);
	}
}


int		main(int ac, char **av)
{
	t_data		data;
	t_philo		*philo;
	t_all		*all;

	if (!ft_parse(ac, av, &data))
		return (1);
	if (!(philo = malloc(sizeof(t_philo) * (data.nb_philo + 1))))
		return (-1);
	if (!(all = malloc(sizeof(t_all) * (data.nb_philo + 1))))
		return (-1);
	printf("nb = %d, death = %d, eat = %d, sleep = %d\n", data.nb_philo,
data.time_death, data.time_eat, data.time_sleep);
	philo_init(philo, &data);
	philo_create(philo, &data, all);
	philo_delete(philo, &data);
	return (0);
}
