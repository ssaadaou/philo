
#include "philo.h"

int check_death(t_philo *philo)
{
    while(1)
    {
        if (time_() - philo->last_meal >= philo->data->time_to_die)
        {
            pthread_mutex_lock(&philo->data->printf_);
            printf("philo %d died\n", philo->id);
            pthread_mutex_unlock(&philo->data->printf_);
            return (-1);
        }
        if (philo->data->num_of_meals > 0 &&
            philo->count_meals >= philo->data->num_of_meals)
        {
            pthread_mutex_lock(&philo->data->printf_);
            printf("philo %d has eaten %d times\n", philo->id, philo->count_meals);
            pthread_mutex_unlock(&philo->data->printf_);
            return (-1);
        }

    }
}