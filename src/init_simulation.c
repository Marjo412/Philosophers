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

int init_simulation(t_data *data)
{}

int init_mutex()
{}
int init_philos(t_philo **philos)
{}