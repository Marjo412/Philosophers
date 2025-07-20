
#ifndef PHILOSOPHERS.H
# define PHILOSOPHERS.H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool>
#include <pthread.h> //mutex, threads
#include <sys/time.h> //gettimeofday
#include <limits.h> //INT_MAX

// ./philo 5 800 200 200 7
typedef pthread_mutex_t t_mtx;

typedef struct s_fork
{
	t_mtx	fork;
	int		fork_id;
}	t_fork;

typedef struct s_philo
{
	int			id;
	long		meals_counter;
	bool		full;
	long		last_meal_time; //time passed from last meal
	t_fork		*left_fork;
	t_fork		*right_fork;
	pthread_t	thread_id; // a philo is a thread
	t_data		*data;
}	t_philo;

typedef struct t_data
{
	long	nbr_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	nbr_meals; //nbr given in command line
	long	start_simulation;
	bool	end_simulation; // when a philo dies or nbr of meals is reach
	t_fork	*fork; // array forks
	t_philo	*philos;
}	s_data;

//utils
int	ft_atoi(const char *str);
int	is_space(char c);
int	is_digit(char c);

#endif