#include "philo.h"

int main(void)
{
	struct timeval a;
	int b;
	gettimeofday(&a, NULL);
	b = a.tv_usec;
	printf("%d, %zd\n", a.tv_usec, a.tv_sec);
	usleep(200 * 1000);
	gettimeofday(&a, NULL);
	printf("%d, %zd\n", a.tv_usec, a.tv_sec);
	printf("%d\n", a.tv_usec - b - 20);
}