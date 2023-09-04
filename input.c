/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:53:15 by ssaadaou          #+#    #+#             */
/*   Updated: 2023/09/04 15:28:19 by ssaadaou         ###   ########.fr       */
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
long long time_(void)
{
    struct timeval time_var;
    gettimeofday(&time_var, NULL);
    long long now;
    now = time_var.tv_sec * 1000 + time_var.tv_usec / 1000;
    return(now);
}

void usleep_(long long chrono)
{
    long long now;
        now = time_();
    while(time_() < (now + chrono))
    {
        usleep(900);
    }
}

void init_philo(t_list *data)
{
    int i = 0; 
    pthread_mutex_lock(&data->hold);
    while(i < data->num_philo)
    { 
        data->ph[i].meals_eaten = 0;
        data->ph[i].id = i + 1;
        data->ph[i].last_meal = time_();
	    pthread_create(&data->ph[i].philo, NULL, &routine, &data->ph[i]);
        pthread_detach(data->ph[i].philo);
        usleep(10);
        i++;
        // if(i + 1 == data->num_philo)
        //    i = 1;
    }
}

void init_fork(t_list *data)
{
    int i = 0;
    pthread_mutex_init(&data->printf_, NULL);
    pthread_mutex_init(&data->hold, NULL);
	pthread_mutex_init(&data->meals_count, NULL);
    while(i < data->num_philo)
    {
        pthread_mutex_init(&data->fork[i], NULL);
        data->ph[i].data = data; 
        i++;
    }
}

int main(int ac, char **av)
{
    t_list args;
    if(valid_input(ac, av, &args))
        return 1;
    args.fork = malloc(sizeof(pthread_mutex_t) * args.num_philo);
    args.ph = malloc(sizeof(t_philo) * args.num_philo);
    init_fork(&args);
    init_philo(&args);
    pthread_mutex_lock(&args.hold);
    pthread_mutex_unlock(&args.hold);
    free(args.fork);
    free(args.ph);
}
