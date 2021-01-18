/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 18:00:15 by lmoulin           #+#    #+#             */
/*   Updated: 2021/01/03 15:33:42 by lmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

int		philo_init(t_philo *philo, t_data *data)
{
	int					i;

	if (!(data->writer = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t))))
		return (0);
	pthread_mutex_init(data->writer, NULL);
	i = -1;
	data->all_meals = false;
	while (++i < data->nb_philo)
	{
		if (!(philo[i].f1 = malloc(sizeof(pthread_mutex_t))))
			return (0);
		pthread_mutex_init(philo[i].f1, NULL);
		if (!(philo[i].locker = malloc(sizeof(pthread_mutex_t))))
			return (0);
		pthread_mutex_init(philo[i].locker, NULL);
		philo[i].idx = i + 1;
		philo[i].last_time_eat = 0;
	}
	i = -1;
	while (++i < data->nb_philo - 1)
		philo[i].f2 = philo[i + 1].f1;
	philo[i].f2 = philo[0].f1;
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
		usleep(10);
	}
	return (1);
}
