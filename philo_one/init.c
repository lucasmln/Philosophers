#include "./philosophers.h"

int		philo_init(t_philo *philo, t_data *data)
{
	int					i;
//	pthread_mutex_t		*fork;

	if (!(data->writer = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t))))
		return (0);
	pthread_mutex_init(data->writer, NULL);
	i = 0;
	while (i < data->nb_philo)
	{
		philo[i].idx = i + 1;
		if (!(philo[i].f1 = malloc(sizeof(pthread_mutex_t))))
			return (0);
//		philo[i].f1 = &fork[i];
		pthread_mutex_init(philo[i].f1, NULL);
		i++;
	}
	i = -1;
	while (++i < data->nb_philo - 1)
		philo[i].f2 = philo[i + 1].f1;
	philo[i].f2 = philo[0].f1;
	return (1);
}

int		philo_create(t_philo *philo, t_data *data, t_all *all)
{
	int		i;

	i = -1;
	gettimeofday(&data->time, NULL);
	data->die = false;
	while (++i < data->nb_philo)
	{
		all[i].philo = &philo[i];
		all[i].data = data;
		if (pthread_create(&philo[i].thread, NULL, &routine, &all[i]))
			return (0);
		usleep(10);
	}
	return (1);
}
