#include "philo.h"

void    sleep(t_philo *philo)
{
    usleep(philo->data->time_to_sleep * 1000);
}

void    eat(t_philo *philo)
{
    usleep(philo->data->time_to_eat * 1000);
}

void    think(t_philo *philo)
{}
