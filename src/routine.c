/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:59:10 by mrosset           #+#    #+#             */
/*   Updated: 2025/08/07 10:22:05 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_sleep(t_philo *philos)
{
	output(philos, BLUE, "is sleeping");
	usleep(philos->data->time_to_sleep * 1000);
}

void	eat(t_philo *philos)
{
	long	now;

	pthread_mutex_lock(&philos->data->meal_mutex);
	now = get_time();
	philos->last_meal_time = now;
	philos->meals_counter ++;
	if (philos->data->nbr_meals > 0
		&& philos->meals_counter >= philos->data->nbr_meals)
		philos->full = true;
	pthread_mutex_unlock(&philos->data->meal_mutex);
	output(philos, MAGENTA, "is eating");
	usleep(philos->data->time_to_eat * 1000);
}

void	think(t_philo *philos)
{
	output(philos, GREEN, "is thinking");
	usleep(100);
}

void	take_forks(t_philo *philos)
{
	pthread_mutex_lock(&philos->left_fork->fork);
	output(philos, YELLOW, "has taken a fork");
	pthread_mutex_lock(&philos->right_fork->fork);
	output(philos, YELLOW, "has taken a fork");
}

void	release_forks(t_philo *philos)
{
	pthread_mutex_unlock(&philos->left_fork->fork);
	pthread_mutex_unlock(&philos->right_fork->fork);
}

/*
**eat : 1.grab left and right fork
          2.eat : write eat, update last meal time, meals counter
         3.put down forks.
**think: usleep is to avoid a too fast sequence if a philo finishes
        his reflexion very quickly.
*/