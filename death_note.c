/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_note.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 20:29:55 by ssaadaou          #+#    #+#             */
/*   Updated: 2023/09/08 00:46:55 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_meals(t_list *data, int ac, int i, int *flag)
{
	pthread_mutex_lock(&data->meals_count);
	if (ac == 6 && data->ph[i].count_meals > data->num_of_meals)
	{
		(*flag)++;
		if(*flag == data->num_philo)
		{
			pthread_mutex_unlock(&data->meals_count);
			return (1);
		}
	}
	pthread_mutex_unlock(&data->meals_count);
	return (0);
	
}

int	check_death(t_list *data, int ac)
{
	int	i;
	int flag;

	flag = 0;
	i = 0;
	while (1)
	{
		usleep(10);
		while (i < data->num_philo)
		{
			pthread_mutex_lock(&data->update_time);
			if (time_() - data->ph[i].last_meal >= data->time_to_die)
			{
				pthread_mutex_lock(&data->printf_);
				data->ph[i].dead = 1;
				printf("%lld %d died\n", (time_() - data->start_time), \
				data->ph[i].id);
				pthread_mutex_unlock(&data->update_time);
				return (1);
			}
				// exit(0);
			pthread_mutex_unlock(&data->update_time);
			if(check_meals(data, ac, i, &flag) != 0)
				return (1);
			i++;
		}
		i = 0;
	}
}
