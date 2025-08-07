/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 09:47:46 by mrosset           #+#    #+#             */
/*   Updated: 2025/08/07 10:31:23 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_data *data)
{
	data->end_simu = false;
	data->start_simulation = 0;
	data->philos = malloc(sizeof(t_philo) * data->nbr_philo);
	data->forks = malloc(sizeof(t_fork) * data->nbr_philo);
	pthread_mutex_init(&data->meal_mutex, NULL);
	pthread_mutex_init(&data->print_mutex, NULL);
}

int	init_mutex(t_data *data)
{
	int		i;
	t_fork	*fork;

	i = 0;
	while (i < data->nbr_philo)
	{
		fork = &data->forks[i];
		fork->fork_id = i;
		if (pthread_mutex_init(&fork->fork, NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	init_philos(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < data->nbr_philo)
	{
		philo = &data->philos[i];
		philo->id = i + 1;
		philo->full = false;
		philo->meals_counter = 0;
		philo->thread_id = 0;
		philo->data = data;
		init_fork(philo, data->forks, i);
		i++;
	}
	return (0);
}

int	init_fork(t_philo *philo, t_fork *fork, int philo_pos)
{
	int	philo_nbr;

	philo_nbr = philo->data->nbr_philo;
	philo->right_fork = &fork[(philo_pos + 1) % philo_nbr];
	philo->left_fork = &fork[philo_pos];
	if (philo->id % 2)
	{
		philo->right_fork = &fork[philo_pos];
		philo->left_fork = &fork[(philo_pos + 1) % philo_nbr];
	}
	return (0);
}

int	init_simulation(t_data *data)
{
	init_data(data);
	if (!data->philos || !data->forks)
		return (0);
	if (init_mutex(data))
		return (0);
	if (init_philos(data))
		return (0);
	return (1);
}

/*
6e4 = 60ms in converstion
**init_data: allocate memory, init globals mutex
**init_mutex: init mutex of each fork
**init_philos: init each philo and link to the forks
**init_simulation: global function to call the others and init all
*/