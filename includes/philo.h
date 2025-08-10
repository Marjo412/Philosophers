/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 09:49:39 by mrosset           #+#    #+#             */
/*   Updated: 2025/08/10 14:50:50 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h> 
# include <pthread.h> //mutex, threads
# include <sys/time.h> //gettimeofday
# include <limits.h> //INT_MAX

# define WHITE "\033[0;37m"		//when philos are full
# define RED "\033[0;31m"		//dead
# define GREEN "\033[0;32m"		//think
# define YELLOW "\033[0;33m"	//fork
# define BLUE "\033[0;34m"		//sleep
# define MAGENTA "\033[0;35m"	//eat

typedef pthread_mutex_t	t_mtx;

typedef struct s_fork
{
	t_mtx	fork;
	int		fork_id;
}	t_fork;

typedef struct s_philo
{
	int				id;
	long			meals_counter;
	bool			full;
	long			last_meal_time;
	t_fork			*left_fork;
	t_fork			*right_fork;
	pthread_t		thread_id;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				nbr_philo;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				nbr_meals;
	long			start_simulation;
	bool			end_simu;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	print_mutex;
	t_fork			*forks;
	t_philo			*philos;
}	t_data;

//input and output
int		valid_input(const char *str);
int		parse_input(t_data *data, char **argv);
void	output(t_philo *philo, char *routine, char *color);

//every functions for the simulation
int		wait_all_threads(t_data	*data);
int		start_dinner(t_data *data);
int		init_simulation(t_data *data);
int		end_simulation(t_data *data);
void	*routine(void *arg);
void	init_data(t_data *data);
int		init_mutex(t_data *data);
int		init_philos(t_data *s_data);
int		init_fork(t_philo *philo, t_fork *fork, int philo_pos);

//routine
void	take_forks(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	eat(t_philo *philo);
void	release_forks(t_philo *philo);
void	think(t_philo *philo);
//void	died(t_philo *philo);

//monitor
void	*monitor(void *arg);
int		check_death(t_data *data);
int		check_full(t_data *data);

//utils
int		ft_atoi(const char *str);
int		is_space(char c);
int		is_digit(char c);
int		one_philo(t_philo *philos);
time_t	get_time(void);

#endif