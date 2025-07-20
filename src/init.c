
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

void	init_data(t_data *data)
{
	data->end_simulation = false;
	data->philos = malloc(sizeof(t_philo) * data->nbr_philo);
	data->forks = malloc(sizeof(t_fork) * data->nbr_philo);
}

int init_simulation(t_data *data)
{}

int init_mutex()
{}
int init_philos(t_data *s_data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = data->philos + i;
	philo->id = i + 1;
	philo->full = false;
	philo->meals_counter = 0;
	philo->data = data;
	i++;
	return (0);
}

/*
6e4 = 60ms in converstion*/