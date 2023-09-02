/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:53:15 by ssaadaou          #+#    #+#             */
/*   Updated: 2023/08/18 22:37:27 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
    while(now < now + chrono);
    {
        now = time_();
        usleep(400);
    }
}


void dinner_time(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->printf_);
    printf("philo %d is eatiiiiiiiigggggggg\n", philo->id);
    pthread_mutex_unlock(&philo->data->printf_);
    pthread_mutex_lock(&philo->data->meals_count);
    philo->count_meals++;
    pthread_mutex_unlock(&philo->data->meals_count);
    if(philo->count_meals == philo->data->num_of_meals)
        return ;
    usleep_(philo->data->time_to_eat * 1000);
    philo->last_meal = time_();
}

void sleep_time(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->printf_);
    printf("philo %d ZZzzzzZZ\n", philo->id);
    pthread_mutex_unlock(&philo->data->printf_);
    usleep_(philo->data->time_to_sleep);
}

void thinking(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->printf_);    
    printf("philo %d is thinkiiiiiiiiiiiiiiiiinnnnnnnnnnnnnnnnnnnnng\n", philo->id);
    pthread_mutex_unlock(&philo->data->printf_);
    usleep_(philo->data->time_to_sleep);
}

void take_forks(t_philo *philo)
{
    if((philo->id % philo->data->num_philo) == philo->data->num_philo - 1)
    {
        printf(">> %d <<\n", philo->id);
    	philo->id = 1;
    }
    pthread_mutex_lock(&philo->data->fork[philo->id - 1]);
    pthread_mutex_lock(&philo->data->printf_);
    printf("philo %d right fork\n", philo->id);
    pthread_mutex_unlock(&philo->data->printf_);
    pthread_mutex_lock(&philo->data->fork[philo->id % philo->data->num_philo]);
    pthread_mutex_lock(&philo->data->printf_);
    printf("philo %d left fork\n", philo->id);
    pthread_mutex_unlock(&philo->data->printf_); 
    dinner_time(philo); 
    pthread_mutex_unlock(&philo->data->fork[philo->id - 1]);
    pthread_mutex_unlock(&philo->data->fork[philo->id % philo->data->num_philo]);
}
void *routine(void *ph)
{
    t_philo *philo = (t_philo *)ph;
    int last_philo = philo->data->num_philo;
    if ((philo->id % 2) == 0)
    {
		usleep_(100 * 1000);
    }

    while(1)
    {
        // if(check_death(philo) == -1)
        //     return NULL;
        take_forks(philo);
        // dinner_time(philo);
        sleep_time(philo);
        thinking(philo);
    }
    return NULL;
}

void init_philo(t_list *data)
{
    int i = 0; 
    while(i < data->num_philo)
    { 
        data->ph[i].meals_eaten = 0;
        data->ph[i].id = i + 1;
        data->ph[i].last_meal = time_();
	    pthread_create(&data->ph[i].philo, NULL, &routine, &data->ph[i]);
        pthread_detach(data->ph[i].philo);
        i++;
        // if(i + 1 == data->num_philo)
        //    i = 1;
    }
}

void init_fork(t_list *data)
{
    int i = 0;
    pthread_mutex_init(&data->printf_, NULL);
	pthread_mutex_init(&data->meals_count, NULL);
	// pthread_mutex_init(&data->ph->next_fork, NULL);
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
}
