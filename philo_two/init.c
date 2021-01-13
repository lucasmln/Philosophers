#include "./philosophers.h"

int		philo_init(t_philo *philo, t_data *data)
{
	int					i;
	sem_t				*fork;
	sem_t				*display;

	sem_unlink("printer");
	sem_unlink("fork");
	display = sem_open("printer", O_CREAT | O_EXCL, S_IRWXU, 1);
	fork = sem_open("fork", O_CREAT | O_EXCL, S_IRWXU, data->nb_philo);
	data->writer = display;
	data->fork = fork;
	i = -1;
	data->all_meals = false;
	while (++i < data->nb_philo)
	{
		philo[i].idx = i + 1;
		philo[i].last_time_eat = 0;
	}
	return (1);
}

int		philo_create(t_philo *philo, t_data *data, t_all *all)
{
	int			i;

	i = -1;
	gettimeofday(&data->time, NULL);
	data->die = false;
	while (++i < data->nb_philo)
	{
		all[i].philo = &philo[i];
		all[i].data = data;
		if (pthread_create(&philo[i].thread, NULL, &routine, &all[i]))
			return (0);
		usleep(50);
	}
	return (1);
}
