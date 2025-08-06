/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marjorie <marjorie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 10:49:42 by mrosset           #+#    #+#             */
/*   Updated: 2025/08/06 17:04:31 by marjorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_death(t_data *data)
{
    int     i;
    t_philo *philo;
    long    now;

    i = 0;
    while (i < data->nbr_philo)
    {
        philo = &data->philos[i];
        pthread_mutex_lock(&data->meal_mutex);
        now = get_time();
        if (now - philo->last_meal_time > data->time_to_die)
        {
            output(philo, RED, "died");
            data->end_simu = true;
            pthread_mutex_unlock(&data->meal_mutex);
            return (1);
        }
        pthread_mutex_unlock(&data->meal_mutex);
        i++;
    }
    return (0);
}

int check_full(t_data *data)
{
    int i;
    int full_count;
    t_philo *philo;

    if (data->nbr_meals <= 0)
        return (0);
    i = 0;
    full_count = 0;
    while (i < data->nbr_philo)
    {
        philo = &data->philos[i];
        pthread_mutex_lock(&data->meal_mutex);
        if (philo->full)
            full_count++;
        pthread_mutex_unlock(&data->meal_mutex);
        i++;
    }
    if (full_count == data->nbr_philo)
        return (1);
    return (0);
}

void    *monitor(void *arg)
{
    t_data  *data;

    data = (t_data *)arg;
    while (!data->end_simu)
    {
        if (check_death(data))
            return (NULL);
        if (check_full(data))
        {
            pthread_mutex_lock(&data->print_mutex);
	        printf(WHITE "All philosophers have eaten %d times ✅\n",
		    data->nbr_meals);
            pthread_mutex_unlock(&data->print_mutex);
            data->end_simu = true;
            return (NULL);
        }
        usleep(1000);
    }
    return (NULL);
}

/*
**check_death : this function check if the authorized survival limit time from
    the last meal is passed, if the condition is true the philo is dead.

**check_full: this function checks how many time the philos have eaten.
    end_simulation if the nbr_meals are reached.

**monitor : main function of the monitor to call the two other functions to
    check if the simulation goes right.
*/