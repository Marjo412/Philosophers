/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marjorie <marjorie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 09:47:46 by mrosset           #+#    #+#             */
/*   Updated: 2025/07/28 21:47:16 by marjorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_data *data)
{
	data->end_simulation = false;
	data->philos = malloc(sizeof(t_philo) * data->nbr_philo);
	data->forks = malloc(sizeof(t_fork) * data->nbr_philo);
	pthread_mutex_init(&data->)
	while ()
	{
		//mutex_handel
	}
}

int init_mutex(t_data *data)
{
	return (0);
}
int init_philos(t_data *s_data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while ()
	{
		philo = data->philos + i;
		philo->id = i + 1;
		philo->full = false;
		philo->meals_counter = 0;
		philo->data = data;
		init_fork(philo, data->fork, i);
		i++;
	}
	return (0);
}

int	init_fork(t_philo *philo, t_fork *fork, int philo_pos)
{
	//left fork = (philo_position + 1) % nbr_philo -> (4 + 1) % 5;
	int	philo_nbr;

	philo_nbr = philo->data->philo_nbr;
	philo->right_fork = &fork[(philo_pos + 1) % philo_nbr];
	philo->left_fork = &fork[philo_pos];
	if (philo->id % 2)
	{
		philo->right_fork = &fork[philo_pos];
		philo->left_fork = &fork[(philo_pos + 1) % philo_nbr];
	}
	return (0);
}

/*
6e4 = 60ms in converstion*/