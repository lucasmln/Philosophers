/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosospher.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 12:26:29 by lmoulin           #+#    #+#             */
/*   Updated: 2021/01/15 14:11:13 by lmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>
# include <string.h>
# include <sys/wait.h>
# include <signal.h>

typedef struct		s_philo
{
	int				idx;
	int				last_time_eat;
	pthread_t		thread;
	pid_t			pid;
}					t_philo;

typedef struct		s_data
{
	sem_t				*fork;
	sem_t				*writer;
	int					nb_philo;
	int					time_death;
	int					time_eat;
	int					time_sleep;
	int					round;
	bool				die;
	bool				all_meals;
	struct timeval		time;
}					t_data;

typedef struct		s_all
{
	t_philo		*philo;
	t_data		*data;
}					t_all;

size_t				ft_strlen(const char *str);
void				ft_strdel(char **s);
char				*ft_uitoa(unsigned int n);
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
int					take_fork(t_all *all);
int					eat(t_all *all);
int					routine(void *arg);
int					philo_init(t_philo *philo, t_data *data);
int					philo_create(t_philo *philo, t_data *data, t_all *all);
int					ft_get_args(char **av, t_data *data);
int					ft_parse(int ac, char **av, t_data *data);
void				writer(t_all *all, const char *str);
int					check_philo_die(t_data *data);
void				philo_delete(t_philo *philo, t_data *data, t_all *all);
unsigned int		get_time(struct timeval start);
void				output_die(t_all *all, const char *str);
void				*checker(void *arg);
int					philo_wait(t_data *data, t_all *all);
#endif
