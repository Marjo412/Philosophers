/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marjorie <marjorie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 09:48:16 by mrosset           #+#    #+#             */
/*   Updated: 2025/07/29 21:55:38 by marjorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	valid_input(t_data *data, const char *str)
{
	int	len;

	len = 0;
	while (is_space(str[len]))
		len++;
	if (str[len] == '+')
		len++;
	else if (str[len] == '-')
		return (printf("Error : positive value only\n"), 1);
	if (!is_digit(str[len]))
		return (printf("Error : the input must be a digit\n", 1));
	while (is_digit(str[len]))
		len++;
	if (str[len] > INT_MAX)
		return (printf("Error : the limit of the value is INT_MAX\n", 1));
	if (nbr_philo < 1 || nbr_philo > 200)
		return (printf("Error : the nbr of philos must be between 1 to 200\n", 1));
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
void	output(t_philo *philo, char *routine, char *color)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	if (!end_simulation(philo->data))
	{
		printf("%ld %d %s\n",color, get_time(), philo->id, routine)
	}
	pthread_mutex_unlock(&philo->data->print_mutex);
}

/*
**valid_input: this function checks if the input is valid
	//0. check special chars, tab, space...
	//1. check for negatives
	//2. check if nb is legit, no letters
	//3. check INT_MAX
**parse_input:
*/