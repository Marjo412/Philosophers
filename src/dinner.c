/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marjorie <marjorie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 09:47:36 by mrosset           #+#    #+#             */
/*   Updated: 2025/07/28 21:48:15 by marjorie         ###   ########.fr       */
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
		pthread_creat();
	}

	return (1);
}

int	start_dinner(t_data *data, pthread_t *thread)
{
	int	i;

	i = -1;
	if (0 == data->nbr_meals)
		return ;
	else if (1 == data->nbr_philo)
		one_philo();//special function
	else
	{
		while ()
			pthread_create(&data->philos[i], start_simulation);
		i++;
	}
}

int init_simulation(t_data *data)
{
	int		i;
	t_philo	*philo;

	data->time = get_time();
	philo = (t_philo *)data;
	if (!one_philo(philos))
		return (0);
	i = 0;
	while (i < data->nbr_philo)
	{
		i++;
	}
}

void	end_simulation(t_data *data)
{
	
}