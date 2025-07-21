
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

int	start_dinner(t_data *data, pthread_t *thread)
{
	int	i;

	i = -1;
	if (0 == data->nbr_meals)
		return ;
	else if (1 == data->nbr_philo)
		//special function
	else
	{
		while ()
			pthread_create();
	}
}