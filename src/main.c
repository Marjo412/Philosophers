/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marjorie <marjorie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 09:48:54 by mrosset           #+#    #+#             */
/*   Updated: 2025/08/01 19:31:03 by marjorie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// ./philo 5 800 200 200 7
int	main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (1);
		//1) check errors
		//2)init_data, create the thing
		//3) start dinner
	init_simulation();
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