/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosset <mrosset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 09:48:54 by mrosset           #+#    #+#             */
/*   Updated: 2025/08/10 14:56:44 by mrosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	if (argc < 5 || argc > 6)
		return ((printf("Error: wrong number of arguments\n")), 1);
	i = 1;
	while (argv[i])
	{
		if (valid_input(argv[i]))
			return (1);
		i++;
	}
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
 ./philo 5 800 200 200 7
**pthread_create: create a thread, a task that run in parallel with main,
	take 4 args.
**pthread_join: wait that a thread finished
**pthread_detach: to not wait a thread, he cleans up alone at the end
**pthread_mutex_init: initialize a mutex a shared resource. Mandatory to 
	do it before using a mutex.
**pthread_mutex_destroy: clean the mutex and the memory after usiing this
	mutex, when we don't need it anymore.
**pthread_mutex_lock: lock the mutex to not use it at the same time in an
	other thread.
**pthread_mutex_unlock: unlock the mutex so the others threads can use it
	if they need it.
**tests : valgrind --tool=drd 
		 valgrind --leak-check=full
*/