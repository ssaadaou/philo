/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:25:46 by ssaadaou          #+#    #+#             */
/*   Updated: 2023/07/07 22:45:36 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

int is_digit(int c)
{
    if(c >= '0' && c <= '9')
        return (1);
    return (0);
}

int ft_atoi(char *s)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while ((s[i] == ' ') || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-')
	{
       	ft_putstr_fd("Error : negative input\n", 2);
        return (1);
	}
	if (s[i] == '0')
	{
		while(s[i] == '0')
			i++;
	}
	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		res = (res * 10) + (s[i] - '0');
		i++;
	}
	return (res);
}

void inits(t_list *data)
{
	data->num_of_meals = 0;
	data->num_philo = 0;
	data->time_to_die = 0;
	data->time_to_eat = 0;
	data->time_to_sleep = 0;
}