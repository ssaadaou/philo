/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:20:59 by ssaadaou          #+#    #+#             */
/*   Updated: 2023/09/06 02:48:32 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_philo(t_list *data)
{
    int i = 0; 
    pthread_mutex_lock(&data->hold);
    while(i < data->num_philo)
    {
        data->ph[i].id = i + 1;
	    pthread_create(&data->ph[i].philo, NULL, &routine, &data->ph[i]);
        pthread_detach(data->ph[i].philo);
        usleep(10);
        i++;
    }
}

void init_fork(t_list *data)
{
    int i = 0;
    pthread_mutex_init(&data->printf_, NULL);
    pthread_mutex_init(&data->hold, NULL);
	pthread_mutex_init(&data->meals_count, NULL);
    pthread_mutex_init(&data->update_time, NULL);
    while(i < data->num_philo)
    {
        pthread_mutex_init(&data->fork[i], NULL);
        data->ph[i].data = data; 
        i++;
    }
}

void leaks()
{
    system("leaks philo");
}
int main(int ac, char **av)
{
    t_list args;
    // args.flag = 1;
    atexit(leaks);
    if(valid_input(ac, av, &args))
        return 1;
    args.fork = malloc(sizeof(pthread_mutex_t) * args.num_philo);
    args.ph = malloc(sizeof(t_philo) * args.num_philo);
    init_fork(&args);
    init_philo(&args);
    // check_death(&args);
    if(check_death(&args, ac) != 0)
        return 1;
    pthread_mutex_lock(&args.hold);
    pthread_mutex_unlock(&args.hold);
    // free(args.fork);
    // free(args.ph);
    while(1);
}