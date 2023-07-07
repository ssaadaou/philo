/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:53:15 by ssaadaou          #+#    #+#             */
/*   Updated: 2023/07/07 22:35:37 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
//check on only digits

//input must not be negative------> if (atoi(av[?]) < 0 (quitee) +++)

void valid_input(int ac, char **av)
{
    t_list *args;
    
    if(ac != 5 && ac != 6)
    {
        ft_putstr_fd("Error : incorrect number of arguments\n", 2);
        return ;
    }
    args = malloc(sizeof(t_list));
    inits(args);
    args->num_philo = ft_atoi(av[1]);
    args->time_to_die = ft_atoi(av[2]);
    args->time_to_eat = ft_atoi(av[3]); 
    args->time_to_sleep = ft_atoi(av[4]);
    if(av[5])
        args->num_of_meals = ft_atoi(av[5]);
}

int main(int ac, char **av)
{
    valid_input(ac, av);
}