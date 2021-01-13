# include "philosophers.h"

unsigned int		get_sec()
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec);
}

unsigned int		get_usec()
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_usec);
}
