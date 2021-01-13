#include "./philosophers.h"

void	philo_delete(t_philo *philo, t_data *data)
{
	int		i;

	i = -1;
	usleep(1000);
	while (++i < data->nb_philo)
		pthread_detach(philo[i].thread);
}

int		check_philo_die(t_data *data)
{
	char		*time;

	while (data->die == false && data->all_meals == false)
		usleep(1000);
	usleep(1000);
	if (data->all_meals == true)
	{
		sem_wait(data->writer);
		time = ft_uitoa(get_time(data->time));
		write(1, ".......", 7 - ft_strlen(time));
		printf("%u all meals are ate\n", get_time(data->time));
		ft_strdel(&time);
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_data		*data;
	t_philo		*philo;
	t_all		*all;

	if (!(data = (t_data *)malloc(sizeof(t_data))))
		return (1);
	if (!ft_parse(ac, av, data))
		return (1);
	if (!(philo = (t_philo *)malloc(sizeof(t_philo) * (data->nb_philo + 1))))
		return (-1);
	if (!(all = (t_all *)malloc(sizeof(t_all) * (data->nb_philo + 1))))
		return (-1);
	philo_init(philo, data);
	philo_create(philo, data, all);
	check_philo_die(data);
	philo_delete(philo, data);
	while (1)
	;
	return (0);
}
