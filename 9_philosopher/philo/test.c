#include "includes/philo.h"

int main(void)
{
	struct timeval tv;
	int	timestamp;

	gettimeofday(&tv, NULL);
	timestamp = tv.tv_usec - 0 + \
		(tv.tv_sec - 0) * 1000000;
	printf("%d\n", timestamp / 1000);
}