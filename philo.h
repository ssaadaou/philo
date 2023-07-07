/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 19:28:30 by ssaadaou          #+#    #+#             */
/*   Updated: 2023/07/07 22:33:27 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    int num_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int num_of_meals;
    
}t_list;

//parsing
int ft_atoi(char *s);
int is_digit(int c);
void	ft_putstr_fd(char *s, int fd);
void inits(t_list *data);

#endif