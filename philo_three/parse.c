/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 12:26:29 by lmoulin           #+#    #+#             */
/*   Updated: 2021/01/15 14:11:13 by lmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

int		ft_error(const char *error)
{
	write(1, error, ft_strlen(error));
	return (0);
}

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
				return (ft_error("You need to use only numbers.\n"));
		}
	}
	if ((data->nb_philo = ft_atoi(av[1])) <= 1)
		return (ft_error("Number of Philosophes need to be more than 1\n"));
	data->time_death = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	if (data->time_death < 30 || data->time_eat < 30 || data->time_sleep < 30)
		return (ft_error("Value of timestamp need to be higher than 30ms\n"));
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
	else
		data->round = -1;
	return (1);
}
