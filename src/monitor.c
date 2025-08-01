#include "philo.h"

void    *monitor(void *arg)
{
    t_data  *data;
    int     i;
    long    now;

    data = (t_data *)arg;
    while (!data->end_simulation)
    {
        i = 0;
        while (i < data->nbr_philo)
        {
            pthread_mutex_lock(&data->meal_mutex);
            now = get_time();
            if (now - data->philos[i].last_meal_time > data->time_to_die)
            {
                output(&data->philos[i], RED, "died\n");
                data->end_simulation = true;
                pthread_mutex_unlock(&data->meal_mutex);
                return (NULL);
        }
        pthread_mutex_unlock(&data->meal_mutex);
        i++;
        }
        usleep(1000);
    }
    return (NULL);
}
