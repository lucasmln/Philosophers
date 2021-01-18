/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 18:00:15 by lmoulin           #+#    #+#             */
/*   Updated: 2021/01/03 15:33:42 by lmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

void	philo_delete(t_philo *philo, t_data *data, t_all *all)
{
	int		i;

	i = -1;
	usleep(1000);
	pthread_mutex_destroy(data->writer);
	free(data->writer);
	while (++i < data->nb_philo)
		free(philo[i].f1);
	i = -1;
	while (++i < data->nb_philo)
		free(philo[i].locker);
	free(all->philo);
	free(all->data);
	free(all);
}

int		check_philo_die(t_data *data)
{
	while (data->die == false && data->all_meals == false)
		usleep(1000);
	usleep(1000);
	if (data->die == false)
		pthread_mutex_lock(data->writer);
	if (data->all_meals == true)
		write(1, "all meals are ate\n", 18);
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
