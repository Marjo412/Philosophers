/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 17:16:33 by marvin            #+#    #+#             */
/*   Updated: 2025/07/20 17:16:33 by marvin           ###   ########.fr       */
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

void	parse_input(char **argv)
{
	?->nbr_philo = ft_atoi(argv[1]);
	?->time_to_die = ft_atoi(argv[2]);
	?->time_to_eat = ft_atoi(argv[3]);
	?->time_to_sleep = ft_atoi(argv[4]);
	if (?->time_to_die < 6e4 || ?->time_to_eat < 6e4 || ?-> time_to_die < 6e4)
		printf("Error : time must be major than 60ms\n");
	if (argv[5])
		?->nbr_meals = ft_atoi(argv[5]);
	else
		?->nbr_meals = -1;
}

int init_simulation(t_data *data)
{}

int init_mutex()
{}
int init_philos(t_philo **philos)
{}

/*
6e4 = 60ms in converstion*/