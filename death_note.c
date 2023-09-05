
#include "philo.h"

void check_death(t_list *data)
{
    int i = 0;
    while(1)
    {
        while(i < data->num_philo)
        {
            if (time_() - data->ph[i].last_meal >= data->time_to_die)
            {
            // printf("waiting time : %lld | time_to_die : %d\n", time_() - data->ph[i].last_meal,data->time_to_die );
                pthread_mutex_lock(&data->printf_);
                printf("philo %d died\n", data->ph[i].id);
                pthread_mutex_unlock(&data->printf_);
                return ;
            }
            // printf("\n \n num of meals : %d , count_meals : %d of philo %d\n",data->num_of_meals ,data->ph->count_meals, data->ph[i].id);
            if (data->num_of_meals > 0 &&
                data->ph->count_meals >= data->num_of_meals)
            {
                puts("here");
                pthread_mutex_lock(&data->printf_);
                printf("philo %d has eaten %d times\n", data->ph[i].id, data->ph[i].count_meals);
                pthread_mutex_unlock(&data->printf_);
                return ;
            }
            // pthread_mutex_unlock(&data->hold);
            i++;
        }
        i = 0;
        usleep(1000);
    }
}