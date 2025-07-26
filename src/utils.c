
#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= 0 && str[i] <= 9)
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return(result * sign);
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	one_philo(t_philo *philos)
{
	if (philos->data->nbr_philo == 1)
	{

	}
	return (1);
}

time_t	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		printf(%s, "Error : gettimeofday\n");
		exit (2);
	return ((time.tv_sec) * 1000 + (time.tv_usec) / 1000); //a checker
}
