/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marjorie <marjorie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 09:47:36 by mrosset           #+#    #+#             */
/*   Updated: 2025/08/05 21:19:43 by marjorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
./philo 5 800 200 200 7
1. If no meals, return ->[0]
2. If only 1 philo -> special function
3. Create all threads, all philos
4. Create monitor thread -> dead philo
5. Syncronize the beginnin of simu
	pthread_create->philo starts running
	every philo start together
6. join every philos
*/

int	wait_all_threads(t_data	*data)
{
	int		i;
	t_philo	*philo;

	if (data->nbr_philo == 1)
		return (0);
	i = 0;
	while (i < data->nbr_philo)
	{
		philo = &data->philos[i];
		pthread_join(philo->thread_id, NULL);
		i++;
	}
	return (0);
}

int	start_dinner(t_data *data)
{
	int			i;
	pthread_t	monitor_thread;
	t_philo		*philo;
	
	data->start_simulation = get_time();
	if (data->nbr_philo == 1)
	{
		one_philo(&data->philos[0]);
		return (1);
	}
	i = 0;
	while (i < data->nbr_philo)
	{
		philo = &data->philos[i];
		philo->last_meal_time = data->start_simulation;
		if (pthread_create(&philo->thread_id, NULL, &routine, philo) != 0)
			return (0);
		i++;
	}
	if (pthread_create(&monitor_thread, NULL, &monitor, data) != 0)
		return (0);
	pthread_detach(monitor_thread);
	return (1);
}

int	end_simulation(t_data *data)
{
	int		i;
	t_fork	*fork;

	i = 0;
	while (i < data->nbr_philo)
	{
		fork = &data->forks[i];
		pthread_mutex_destroy(&fork->fork);
		i++;
	}
	pthread_mutex_destroy(&data->meal_mutex);
	pthread_mutex_destroy(&data->print_mutex);
	free(data->philos);
	free(data->forks);
	return (1);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (get_time() < philo->data->start_simulation)
		usleep(100);
	if (philo->id % 2 == 0)
		usleep(100);
	//else
	//	usleep(philo->data->time_to_eat * 200);
	while (!philo->data->end_simu)
	{
		take_forks(philo);
		eat(philo);
		release_forks(philo);
		philo_sleep(philo);
		think(philo);
	}
	return (NULL);
}

/*
philo routine: 1.grab left and right fork
		  		2.eat
				3.put down forks.
				4.sleep
				5.think
	end simulation if end_simulation is true
					if philo dies
*/