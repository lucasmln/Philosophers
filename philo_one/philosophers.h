#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>
# include <semaphore.h>


# include <string.h>
# include <sys/wait.h>


typedef struct	s_philo
{
	int				idx;
	pthread_t		thread;
	pthread_mutex_t	*f1;
	pthread_mutex_t *f2;
}				t_philo;

typedef struct  s_data
{
	pthread_mutex_t	*writer;
//	pthread_mutex_t	*locker;
	int		nb_philo;
	int		time_death;
	int		time_eat;
	int		time_sleep;
	int		round;
	bool	die;
	struct timeval	time;
}               t_data;

typedef struct	s_all
{
	t_philo		*philo;
	t_data		*data;
}				t_all;

size_t				ft_strlen(const char *str);
void				ft_strdel(char **s);
char				*ft_uitoa(unsigned int n);
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
unsigned int		get_sec();
unsigned int		get_usec();
int					take_fork(t_all *all);
int					sleeping(t_all *all);
int					eat(t_all *all);
int					thinking(t_all *all);
void				*routine(void *arg);
int					philo_init(t_philo *philo, t_data *data);
int					philo_create(t_philo *philo, t_data *data, t_all *all);
int					ft_get_args(char **av, t_data *data);
int					ft_parse(int ac, char **av, t_data *data);
void				writer(t_all *all, const char *str);

#endif
