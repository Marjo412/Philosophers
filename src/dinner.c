/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marjorie <marjorie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 09:47:36 by mrosset           #+#    #+#             */
/*   Updated: 2025/08/06 17:15:16 by marjorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
**philo routine: 1.grab left and right fork
		  		2.eat
				3.put down forks
				4.sleep
				5.think
				*repet

**wait_all_threads: this function wait all philos threads except the 
	monitor_thread. Not call if there is only one philo. 
	**pthread_join = we  want to wait that all philos have finished
	his routine (have eaten the nbr_meals or someone died). So the function main
	lock all philo threads until the end and then manage a clean end of the
	simulation and free the memory

**start_simulation: pthread_detach = we don't need to wait this thread because
	it's not a philo thread, it's only for the monitor who check if a philo die
	of if they have all eaten. this monitor_thread end automatically when the
	simulation is finished.
*/