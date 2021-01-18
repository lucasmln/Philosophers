/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 12:26:29 by lmoulin           #+#    #+#             */
/*   Updated: 2021/01/15 14:11:13 by lmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		philo_wait(t_data *data, t_all *all)
{
	int		i;
	int		status;

	i = -1;
	usleep(1000);
	while (++i < data->nb_philo)
	{
		waitpid(all[i].philo->pid, &status, WNOHANG);
		status /= 256;
		if (status == 1)
			data->die = true;
		if (status == 2)
			data->all_meals = true;
		if (status == 1 || status == 2)
			break ;
		if (i + 1 == data->nb_philo)
			i = -1;
	}
	if (data->die == false)
		data->all_meals = true;
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
		all[i].philo->pid = fork();
		if (all[i].philo->pid == 0)
		{
			routine(&all[i]);
			exit(all[i].data->die);
		}
		usleep(30);
	}
	philo_wait(data, all);
	return (1);
}
