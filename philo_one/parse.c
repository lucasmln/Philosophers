# include "./philosophers.h"

int		ft_get_args(char **av, t_data *data)
{
	int		i;
	int		k;

	i = 0;
	while (av[++i])
	{
		k = -1;
		while (av[i][++k])
		{
			if (!ft_isdigit(av[i][k]))
			{
				write(1, "You need to use only numbers.\n", 30);
				return (0);
			}
		}
	}
	data->nb_philo = ft_atoi(av[1]);
	data->time_death = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	return (1);
}

int		ft_parse(int ac, char **av, t_data *data)
{
	if (ac != 6 && ac != 5)
	{
		write(1, "Not good numbers of arguments\n", 30);
		return (0);
	}
	if (!ft_get_args(av, data))
		return (0);
	if (ac == 6)
		data->round = ft_atoi(av[5]);
	return (1);
}


