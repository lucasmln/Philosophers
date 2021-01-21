/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 12:26:29 by lmoulin           #+#    #+#             */
/*   Updated: 2021/01/15 14:11:13 by lmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

void	philo_delete(t_philo *philo, t_data *data, t_all *all)
{
	int		i;

	i = -1;
	usleep(1000);
	while (++i < data->nb_philo)
		kill(philo[i].pid, SIGKILL);
	free(all->data);
	free(all->philo);
	free(all);
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
	philo_delete(philo, data, all);
	return (0);
}
