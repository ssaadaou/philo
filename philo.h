/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:28:30 by ssaadaou          #+#    #+#             */
/*   Updated: 2023/08/14 16:23:15 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
typedef struct s_philo
{
    int id;
    pthread_t philo;
    long long last_meal;
    struct s_list *data;

}   t_philo;

typedef struct s_list
{
    int num_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int num_of_meals;
    pthread_mutex_t printf_;
    pthread_mutex_t *fork;
    t_philo *ph;
    

}t_list;


//parsing

int ft_atoi(char *s);
int is_digit(char *s);
void	ft_putstr_fd(char *s, int fd);
void inits(t_list *data);

#endif