/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marjorie <marjorie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 09:49:39 by mrosset           #+#    #+#             */
/*   Updated: 2025/07/29 21:56:46 by marjorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO.H
# define PHILO.H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h> //memset
# include <pthread.h> //mutex, threads
# include <sys/time.h> //gettimeofday
# include <limits.h> //INT_MAX

# define WHITE "\033[0;37m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define RESET "\033[0m"

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

//input and output
int		valid_input(t_data *data, const char *str);
void	parse_input(t_data *data, char **argv);
void	output(t_philo *philo, char *routine, char *color);

//every functions for the simulation
int		wait_all_threads(t_data	*data);
int		start_dinner(t_data *data, pthread_t *thread);
int		init_simulation(t_data *data);
void	end_simulation(t_data *data);
void	init_data(t_data *data);
int		init_mutex(t_data *data);
int		init_philos(t_data *s_data);
int		init_fork(t_philo *philo, t_fork *fork, int philo_pos);

//routine
void    sleep(t_philo *philo);
void    eat(t_philo *philo);
void    think(t_philo *philo);
void    died(t_philo *philo);

//utils
int		ft_atoi(const char *str);
int		is_space(char c);
int		is_digit(char c);
int		one_philo(t_philo *philos);
time_t	get_time(void);

#endif