
#include "philo.h"

int check_death(t_philo *philo)
{
    while(1)
    {
        if (time_() - philo->last_meal >= philo->data->time_to_die)
        {
            // printf("now time : %lld // lastmeal : %lld\n", time_() , philo->last_meal);
            // printf("waiting time : %lld | time_to_die : %d\n", time_() - philo->last_meal,philo->data->time_to_die );
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
        // pthread_mutex_unlock(&philo->data->hold);

    }
}