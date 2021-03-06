/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 12:26:29 by lmoulin           #+#    #+#             */
/*   Updated: 2021/01/15 14:11:13 by lmoulin          ###   ########.fr       */
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

	gettimeofday(&now, NULL);
	value = get_time(all->data->time);
	time = ft_uitoa(value);
	idx = ft_uitoa((unsigned long)all->philo->idx);
	sem_wait(all->data->writer);
	write(1, ".......", 7 - ft_strlen((const char *)time));
	write(1, time, ft_strlen((const char*)time));
	write(1, " ", 1);
	write(1, idx, ft_strlen(idx));
	write(1, " ", 1);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	sem_post(all->data->writer);
	ft_strdel(&idx);
	ft_strdel(&time);
}

void			output_die(t_all *all, const char *str)
{
	struct timeval	now;
	char			*time;
	char			*idx;
	unsigned int	value;

	gettimeofday(&now, NULL);
	value = get_time(all->data->time);
	time = ft_uitoa(value);
	idx = ft_uitoa((unsigned long)all->philo->idx);
	sem_wait(all->data->writer);
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
