
#include "philo.h"

int check_death(t_list *data, int ac)
{
    int i = 0;
    // (void) ac;
    while(1)
    {
        usleep_(700);
        while(i < data->num_philo)
        {
            if (time_() - data->ph[i].last_meal >= data->time_to_die)
            {
            // printf("waiting time : %lld | time_to_die : %d\n", time_() - data->ph[i].last_meal,data->time_to_die );
                pthread_mutex_lock(&data->printf_);
                printf("philo %d died\n", data->ph[i].id);
                // pthread_mutex_unlock(&data->printf_);
                return 1;
            }
            if (ac == 6 && data->ph->count_meals >= data->num_of_meals)
            {
            printf("\n \n num of meals : %d , count_meals : %d of philo %d\n",data->num_of_meals ,data->ph->count_meals, data->ph[i].id);
                pthread_mutex_lock(&data->printf_);
                printf("philo %d has eaten %d times\n", data->ph[i].id, data->ph[i].count_meals);
                // pthread_mutex_unlock(&data->printf_);
                // data->flag = 0;
                return 1;
            }
            // pthread_mutex_unlock(&data->hold);
            i++;
        }
        i = 0;
    }
}