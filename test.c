/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:22:23 by ssaadaou          #+#    #+#             */
/*   Updated: 2023/09/04 15:33:49 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
int main()
{
    pthread_mutex_t lool;
    
    pthread_mutex_init(&lool, NULL);
    pthread_mutex_lock(&lool);

    pthread_mutex_lock(&lool);
    
    printf("loooool\n");
    
}
 // if((philo->.id % philo->data->num_philo) == philo->data->num_philo - 1)
    // {
    //     printf(">> %d <<\n", philo->id);
    // 	philo->id = 1;
    // }
    //   int right_fork_index = philo->id - 1;
    // int left_fork_index = philo->id % philo->data->num_philo;
    // printf("Debug: id=%d, num_philo=%d, right_fork_index=%d, left_fork_index=%d\n",
    //    philo->id, philo->data->num_philo, right_fork_index, left_fork_index);

    // if (right_fork_index < 0 || right_fork_index >= philo->data->num_philo ||
    //     left_fork_index < 0 || left_fork_index >= philo->data->num_philo) {
    //     printf("Index out of bounds.\n");
    //     exit(1);
    // }