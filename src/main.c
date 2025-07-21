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
**pthread_mutex_init:
**pthread_mutex_destroy:
**pthread_mutex_lock:
**pthread_mutex_unlock:*/