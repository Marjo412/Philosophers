/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marjorie <marjorie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 09:47:36 by mrosset           #+#    #+#             */
/*   Updated: 2025/08/01 16:27:28 by marjorie         ###   ########.fr       */
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
	t_philo	*current;

	current = data->philos;
	i = 0;
	while (i < data->nbr_philo)
	{
		pthread_create();
	}

	return (1);
}

int	start_dinner(t_data *data, pthread_t *thread)
{
	int	i;
	pthread_t monitor_thread;

	data->start_simulation = get_time();
	i = -1;
	if (0 == data->nbr_meals)
		return ;
	else if (1 == data->nbr_philo)
		one_philo(&data->philos[0]);
		return (1);
	else
	{
		while ()
			pthread_create(&data->philos[i], start_simulation);
		i++;
	}
}

int	init_simulation(t_data *data)
{
	data->time = get_time();
	if (data->nbr_philo == 1)
	{
		if (!one_philo(data->philos))
			return (0);
	}
	//init_data
	//init_mutex
	return (1);
}

void	end_simulation(t_data *data)
{
	
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(1000);
	else
		usleep(philo->data->time_to_eat * 1000);
	while (!philo->data->end_simulation)
	{
		take_forks(philo);
		eat(philo);
		relase_forks(philo);
		sleep(philo);
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