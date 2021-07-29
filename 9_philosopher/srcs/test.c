#include "philo.h"

int main(void)
{
    struct timeval a;
    gettimeofday(&a, NULL);
    printf("%ld\n", a.tv_usec / 1000 + a.tv_sec * 1000);
}