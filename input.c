/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:53:15 by ssaadaou          #+#    #+#             */
/*   Updated: 2023/07/20 04:58:42 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int args_as_digit(int ac, char **av)
{
	int i = 1;

	while (i < ac) 
    {
		if (!is_digit(av[i])) 
        {
			return (0);
		}
		i++;
	}
	return (1);
}

int valid_input(int ac, char **av , t_list *args)
{
    if(ac != 5 && ac != 6)
    {
        printf("Error: incorrect number of arguments\n");
        return 1;
    }
    if(!args_as_digit(ac, av))
    {
        printf("Error: arguments must be digits and positive\n");
        return 1;
    }
    inits(args);
    args->num_philo = ft_atoi(av[1]);
    args->time_to_die = ft_atoi(av[2]);
    args->time_to_eat = ft_atoi(av[3]); 
    args->time_to_sleep = ft_atoi(av[4]);
    if(av[5])
        args->num_of_meals = ft_atoi(av[5]);
    return(0);
}

int main(int ac, char **av)
{
    t_list args;
    if(valid_input(ac, av, &args))
        return 1; 
    // int i = 0;
    printf("philo number total = %d\n", args.num_philo);
    // while(i < args.num_philo)
    // {
        
    // }
}