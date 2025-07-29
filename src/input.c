/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 09:48:16 by mrosset           #+#    #+#             */
/*   Updated: 2025/07/29 16:09:22 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	valid_input(const char *str)
{
	int	len;
	//1. check for negatives
	//2. check if nb is legit
	//3. check INT_MAX
	while (is_space(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		return (printf("Error : positive value only\n"), 1);
	if (!is_digit(*str))
		return (printf("Error : the input must be a digit\n", 1));
	while (is_digit(*str++))
		len++;
	if (len > 10)
		return (printf("Error : the limit of the value is INT_MAX\n", 1));
	return (0);
}

void	parse_input(t_data *data, char **argv)
{
	data->nbr_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (data->time_to_die < 6e4 || data->time_to_eat < 6e4
		|| data-> time_to_die < 6e4)
		printf("Error : time must be major than 60ms\n");
	if (argv[5])
		data->nbr_meals = ft_atoi(argv[5]);
	else
		data->nbr_meals = -1;
}

// [time_ms] [philo_id] [action] print the output
void	output(t_philo *philo)
{
	pthread_mutex_unlock(&philo->data->print_mutex);
}
