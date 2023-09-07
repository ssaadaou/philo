/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:43:56 by ssaadaou          #+#    #+#             */
/*   Updated: 2023/09/08 00:51:03 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void dinner_time(t_philo *philo)
{
	// if(philo->count_meals == philo->data->num_of_meals)
	//     return ;
	pthread_mutex_lock(&philo->data->printf_);
	printf("%lld %d is eating\n", (time_() - philo->data->start_time),philo->id);
	pthread_mutex_unlock(&philo->data->printf_);
	pthread_mutex_lock(&philo->data->update_time);
	philo->last_meal = time_();

	usleep_(philo->data->time_to_eat);//lock

	pthread_mutex_unlock(&philo->data->update_time);
	pthread_mutex_lock(&philo->data->meals_count);
	if (philo->data->num_of_meals != 0)
		philo->count_meals++;
	// printf("meals_count >>>> %d\n", philo->count_meals);
	pthread_mutex_unlock(&philo->data->meals_count);
	pthread_mutex_unlock(&philo->data->fork[philo->id - 1]);
	pthread_mutex_unlock(&philo->data->fork[philo->id % \
	philo->data->num_philo]);
}

void	sleep_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->printf_);
	printf("%lld %d is sleeping\n", (time_() - philo->data->start_time), \
	philo->id);
	pthread_mutex_unlock(&philo->data->printf_);

	usleep_(philo->data->time_to_sleep);
	
}

void	thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->printf_);
	printf("%lld %d is thinking\n", (time_() - philo->data->start_time), \
	philo->id);
	pthread_mutex_unlock(&philo->data->printf_);
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork[philo->id - 1]);
	pthread_mutex_lock(&philo->data->printf_);
	printf("%lld %d has taken a fork\n", (time_() - philo->data->start_time), \
	philo->id);
	pthread_mutex_unlock(&philo->data->printf_);
	
	pthread_mutex_lock(&philo->data->fork[philo->id % philo->data->num_philo]);
	pthread_mutex_lock(&philo->data->printf_);
	printf("%lld %d has taken a fork\n", (time_() - philo->data->start_time), \
	philo->id);
	pthread_mutex_unlock(&philo->data->printf_);
}

void	*routine(void *ph)
{
	t_philo	*philo;

	philo = (t_philo *)ph;
	pthread_mutex_lock(&philo->data->update_time);
	philo->last_meal = time_();
	pthread_mutex_unlock(&philo->data->update_time);
	// if (philo->id % 2 == 0)
	// 	usleep(50);
	while (1)
	{
		if (philo->dead == 1)
			return NULL;
		take_forks(philo);
		dinner_time(philo);
		sleep_time(philo);
		thinking(philo);
	}
	return (NULL);
}
