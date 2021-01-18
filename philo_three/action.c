/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 12:26:29 by lmoulin           #+#    #+#             */
/*   Updated: 2021/01/15 14:11:13 by lmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

int			routine(void *arg)
{
	t_all		*all;
	int			i;
	pthread_t	check;

	all = (t_all *)arg;
	i = 0;
	while (all->data->die == false && all->data->all_meals == false)
	{
		pthread_detach(check);
		pthread_create(&check, NULL, &checker, all);
		take_fork(all);
		eat(all);
		writer(all, "is sleeping");
		usleep(all->data->time_sleep * 1000);
		writer(all, "is thinking");
		i++;
		if (all->data->round > 0 && i >= all->data->round)
			all->data->all_meals = true;
	}
	if (all->data->die == true)
		exit(1);
	if (all->data->all_meals == true)
		exit(2);
	return (all->data->die);
}

void		*checker(void *arg)
{
	t_all			*all;
	unsigned int	now;

	all = (t_all *)arg;
	usleep(all->data->time_death * 1000);
	now = get_time(all->data->time);
	if (now - all->philo->last_time_eat >= (unsigned int)all->data->time_death)
	{
		all->data->die = true;
		output_die(all, "is dead");
		exit(1);
	}
	return (NULL);
}

int			take_fork(t_all *all)
{
	sem_wait(all->data->fork);
	sem_wait(all->data->fork);
	writer(all, "has taken a fork");
	writer(all, "has taken a fork");
	return (1);
}

int			eat(t_all *all)
{
	writer(all, "is eating");
	all->philo->last_time_eat = get_time(all->data->time);
	usleep(all->data->time_eat * 1000);
	sem_post(all->data->fork);
	sem_post(all->data->fork);
	return (1);
}
