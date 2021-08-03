#include "philo.h"

int main(void)
{
    pthread_mutex_t *a;
    int b;

    b = 0;
    a = malloc(sizeof(pthread_mutex_t) * 1);
    b = pthread_mutex_init(&a[0], NULL);
    printf("%d\n", b);
    b = pthread_mutex_lock(&a[2]);
    printf("%d\n", b);
}