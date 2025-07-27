/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 09:49:39 by mrosset           #+#    #+#             */
/*   Updated: 2025/07/27 09:50:58 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO.H
# define PHILO.H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool>
# include <pthread.h> //mutex, threads
# include <sys/time.h> //gettimeofday
# include <limits.h> //INT_MAX

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

// ./philo 5 800 200 200 7
typedef struct t_data
{
	time_t			time;
	int				nbr_philo;
	t_time			time_to_die;
	t_time			time_to_eat;
	t_time			time_to_sleep;
	int				nbr_meals; //nbr given in command line
	int				start_simulation;
	bool			end_simulation; // when a philo dies or nbr of meals is reach
	pthread_mutex_t	dinner_mutex;
	t_fork			*forks; // array forks
	t_philo			*philos;
}	s_data;

//parsing


//utils
int	ft_atoi(const char *str);
int	is_space(char c);
int	is_digit(char c);

#endif