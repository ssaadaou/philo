/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:43:56 by ssaadaou          #+#    #+#             */
/*   Updated: 2023/09/04 17:26:07 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void dinner_time(t_philo *philo)
{
    if(philo->count_meals == philo->data->num_of_meals)
        return ;
    pthread_mutex_lock(&philo->data->printf_);
    printf("philo %d is eatiiiiiiiigggggggg\n", philo->id);
    pthread_mutex_unlock(&philo->data->printf_);
    usleep(philo->data->time_to_eat * 1000);
    philo->last_meal = time_();
    pthread_mutex_lock(&philo->data->meals_count);
    philo->count_meals++;
    printf("meals_count >>>> %d\n", philo->count_meals);
    pthread_mutex_unlock(&philo->data->meals_count);
    pthread_mutex_unlock(&philo->data->fork[philo->id - 1]);
    pthread_mutex_unlock(&philo->data->fork[philo->id % philo->data->num_philo]);
}

void sleep_time(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->printf_);
    printf("philo %d ZZzzzzZZ\n", philo->id);
    pthread_mutex_unlock(&philo->data->printf_);
    usleep(philo->data->time_to_sleep * 1000);
}

void thinking(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->printf_);    
    printf("philo %d is thinkiiiiiiiiiiiiiiiiinnnnnnnnnnnnnnnnnnnnng\n", philo->id);
    pthread_mutex_unlock(&philo->data->printf_);
}

void take_forks(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->fork[philo->id - 1]);
    pthread_mutex_lock(&philo->data->printf_);
    printf("philo %d right fork\n", philo->id);
    pthread_mutex_unlock(&philo->data->printf_);
    pthread_mutex_lock(&philo->data->fork[philo->id % philo->data->num_philo]);
    pthread_mutex_lock(&philo->data->printf_);
    printf("philo %d left fork\n", philo->id);
    pthread_mutex_unlock(&philo->data->printf_); 
}
void *routine(void *ph)
{
    t_philo *philo = (t_philo *)ph;
    int last_philo = philo->data->num_philo;
    int i = 1;

    while(1)
    {
        take_forks(philo);
        dinner_time(philo);
        sleep_time(philo);
        thinking(philo);      

    }
    if(check_death(philo) == -1)
        return NULL;
    return NULL;
}
