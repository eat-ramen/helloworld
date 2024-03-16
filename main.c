#include <uk/alloc.h>
#include <uk/boot.h>
#include <uk/arch/lcpu.h>
#include <uk/sched.h>
#include <uk/schedcoop.h>
#include <uk/process.h>
#include <stdio.h>
#include <pthread.h>

#define NUM_ROUNDS	100
#define NUM_THREADS	10

static unsigned long sum = 0;

static void *thread_func(void *arg)
{
	size_t v = (size_t) arg;
	size_t i;

	for (i = 0; i < NUM_ROUNDS; i++) {
		sum += v;
		
	}

	return NULL;
}

int main(void)
{
	size_t i;
	pthread_t th[NUM_THREADS];
	int rc;

	printf("\nhere in main\n");
	for (i = 0; i < NUM_THREADS; i++) {
		rc = pthread_create(&th[i], NULL, thread_func, (void *) i);
		printf("\npthread create in main\n");
	}

	for (i = 0; i < NUM_THREADS; i++) {
		rc = pthread_join(th[i], NULL);
		printf("\npthread join in main\n");
	}

	

	printf("sum is: %lu\n", sum);

	return 0;
}
