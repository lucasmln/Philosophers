/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 18:00:15 by lmoulin           #+#    #+#             */
/*   Updated: 2021/01/03 15:33:42 by lmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

unsigned int	get_time(struct timeval start)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	now.tv_sec = now.tv_sec - start.tv_sec;
	return ((((unsigned int)now.tv_sec * 1000000 + now.tv_usec)
			- start.tv_usec) / 1000);
}

void			writer(t_all *all, const char *str)
{
	struct timeval	now;
	char			*time;
	char			*idx;
	unsigned int	value;

	pthread_mutex_lock(all->data->writer);
	gettimeofday(&now, NULL);
	value = get_time(all->data->time);
	time = ft_uitoa(value);
	idx = ft_uitoa((unsigned long)all->philo->idx);
	write(1, ".......", 7 - ft_strlen((const char *)time));
	write(1, time, ft_strlen((const char*)time));
	write(1, " ", 1);
	write(1, idx, ft_strlen(idx));
	write(1, " ", 1);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	pthread_mutex_unlock(all->data->writer);
	ft_strdel(&idx);
	ft_strdel(&time);
}

void			output_die(t_all *all, const char *str)
{
	struct timeval	now;
	char			*time;
	char			*idx;

	pthread_mutex_lock(all->data->writer);
	gettimeofday(&now, NULL);
	time = ft_uitoa(all->philo->last_time_eat + all->data->time_death);
	idx = ft_uitoa((unsigned long)all->philo->idx);
	write(1, ".......", 7 - ft_strlen((const char *)time));
	write(1, time, ft_strlen((const char*)time));
	write(1, " ", 1);
	write(1, idx, ft_strlen(idx));
	write(1, " ", 1);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	ft_strdel(&idx);
	ft_strdel(&time);
}
