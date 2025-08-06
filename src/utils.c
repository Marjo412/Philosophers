/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marjorie <marjorie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 09:49:05 by mrosset           #+#    #+#             */
/*   Updated: 2025/08/06 17:12:27 by marjorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] <= '0' && str[i + 1] >= '9')
			return (0);
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	one_philo(t_philo *philos)
{
	output(philos, YELLOW, "has taken a fork");
	usleep(philos->data->time_to_die * 1000);
	output(philos, RED, "died");
	philos->data->end_simu = true;
	return (1);
}

time_t	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
	{
		printf("Error : gettimeofday failed\n");
		return (0);
	}
	return ((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000);
}

/*
**gettimeofday():is a function who return the current time based on a reference
	point (January 1, 1970 at 00:00:00 UTC). This is the Unix epoch time. This
	makes easier to compare times and calculate time differences.
	
**get_time: is use to get the current time in milliseconds, because we
	need to manage time_to_die, time_to_eat and time_to_sleep.
**(tv.tv_sec) * 1000 + (tv.tv_usec) / 1000): convert seconds to milliseconds
	and microseconds to milliseconds. tv is a variable from the struct timeval.
	
**one_philo: is a special function in case there is only one philosopher.
	It will take a fork, sleep for time_to_die and then die.
*/