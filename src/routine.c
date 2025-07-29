/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marjorie <marjorie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:59:10 by mrosset           #+#    #+#             */
/*   Updated: 2025/07/29 22:00:20 by marjorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    sleep(t_philo *philo)
{
    output(philo, BLUE, "is sleeping\n");
    usleep(philo->data->time_to_sleep * 1000);
}

void    eat(t_philo *philo)
{
    output(philo, MAGENTA, "is eating\n");
    usleep(philo->data->time_to_eat * 1000);
}

void    think(t_philo *philo)
{
    output(philo, GREEN, "is thinking\n");
}

void    died(t_philo *philo)
{
    output(philo, RED, "died\n");
    philo->data->end_simulation = true;
}

/*
**eat : 1.grab left and right fork
          2.eat : write eat, update last meal time, meals counter
         3.put down forks.
*/