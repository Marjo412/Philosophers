/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marjorie <marjorie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:59:10 by mrosset           #+#    #+#             */
/*   Updated: 2025/08/02 19:38:21 by marjorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    philo_sleep(t_philo *philos)
{
    output(philos, BLUE, "is sleeping\n");
    usleep(philos->data->time_to_sleep * 1000);
}

void    eat(t_philo *philos)
{
    pthread_mutex_lock(&philos->data->meal_mutex);
    philos->last_meal_time = get_time();
    philos->meals_counter ++;
    pthread_mutex_unlock(&philos->data->meal_mutex);
    output(philos, MAGENTA, "is eating\n");
    usleep(philos->data->time_to_eat * 1000);
}

void    think(t_philo *philos)
{
    output(philos, GREEN, "is thinking\n");
    usleep(1000);
}

void    died(t_philo *philos)
{
    output(philos, RED, "died\n");
    philos->data->end_simulation = true;
}

void    take_forks(t_philo *philos)
{
    pthread_mutex_lock(&philos->left_fork->fork);
    output(philos, YELLOW, "has taken a fork\n");
    pthread_mutex_lock(&philos->right_fork->fork);
    output(philos, YELLOW, "has taken a fork\n");
}

void    release_forks(t_philo *philos)
{
    pthread_mutex_unlock(&philos->left_fork->fork);
    pthread_mutex_unlock(&philos->right_fork->fork);
    //output(philo, YELLOW, "has released forks\n");
}

/*
**eat : 1.grab left and right fork
          2.eat : write eat, update last meal time, meals counter
         3.put down forks.
**think: usleep is to avoid a too fast sequence if a philo finishes
        his reflexion very quickly.
*/