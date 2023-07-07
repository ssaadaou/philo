#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void    *myfunc(void *args)
{
    printf("HELLO THREAD\n");
    // while (1)
    // {
    //     /* code */
    // }
    
    return NULL;
}

void    *myfunc1(void *args)
{
    printf("HELLO THREAD1\n");
    // while (1)
    // {
    //     /* code */
    // }
    
    return NULL;
}

void    *myfunc2(void *args)
{
    printf("HELLO THREAD2\n");
    // while (1)
    // {
    //     /* code */
    // }
    
    return NULL;
}
int main()
{
    pthread_t thread;
    pthread_t thread1;
    pthread_t thread2;

    pthread_create(&thread, NULL, myfunc, NULL);
    pthread_create(&thread1, NULL, myfunc1, NULL);
    pthread_create(&thread2, NULL, myfunc2, NULL);
    
    pthread_join(thread, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("finshed\n");

    return (0);
}