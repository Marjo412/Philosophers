
#include "philo.h"

int check_death(t_data *data)
{
    int     i;
    t_philo *philo;
    long    now;

    i = 0;
    while (i < data->nbr_philo)
    {
        philo = &data->philos[i];
        pthread_mutex_lock(&data->meal_mutex);
        now = get_time();
        if (now - philo->last_meal_time > data->time_to_die)
        {
            output(philo, RED, "died\n");
            data->end_simulation = true;
            pthread_mutex_unlock(&data->meal_mutex);
            return (1);
        }
        pthread_mutex_unlock(&data->meal_mutex);
        i++;
    }
    return (0);
}

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

/*
**check_death : this function check if the authorized survival limit time from
    the last meal is passed, if the condition is true the philo is dead.
**check_full: this function checks how many time the philos have eaten.
    end_simulation if the nbr_meals are reached.
*/