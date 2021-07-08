#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

void *asd(void *a)
{
	pthread_t tid = 0;

	tid = pthread_self();
	printf("%s : ", (char *)a);
	printf("%x\n", (unsigned int)tid);
	return (0);
}

int main(void)
{
	pthread_t thread[3];

	if (pthread_create(&thread[0], NULL, asd, "thread_1"))
		printf("Error_1\n");
	if (pthread_create(&thread[1], NULL, asd, "thread_2"))
		printf("Error_2\n");
	if (pthread_create(&thread[2], NULL, asd, "thread_3"))
		printf("Error_3\n");
	sleep(1);
	return (0);
}
