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
    pthread_mutex_unlock(&lool);
    
}
