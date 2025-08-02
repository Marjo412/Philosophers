/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marjorie <marjorie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 09:48:54 by mrosset           #+#    #+#             */
/*   Updated: 2025/08/02 19:18:28 by marjorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// ./philo 5 800 200 200 7
int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
		return ((printf("Error: wrong number of arguments\n")), 1);
	if (!parse_input(&data, argv))
		return (1);
	if (!init_simulation(&data))
		return (printf("Error: init_simulation failed\n"), 1);
	if (!start_dinner(&data))
		return (printf("Error: start_dinner failed\n"), 1);
	wait_all_threads(&data);
	end_simulation(&data);
	return (0);
}

/*
main: we want at least 5 and at most 6 args

**pthread_create: take 4 args
**pthread_join:
**pthread_detach:
**pthread_mutex_init:
**pthread_mutex_destroy:
**pthread_mutex_lock:
**pthread_mutex_unlock:*/