#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

// gcc monteCarlo3.c -o monteCarlo3 -pthread
// time ./monteCarlo3

void* calculate_pi(void* arg) {
	unsigned int seed = time(NULL);
	int circle_points = 0;
	int square_points = 0;
	int intervals = *((int*)arg);  // how to pass the arguments.

	for (int i = 0; i<intervals*intervals; ++i) {
		double rand_x = (double)rand_r(&seed)/RAND_MAX;
		double rand_y = (double)rand_r(&seed)/RAND_MAX;

		if ((rand_x*rand_x + rand_y*rand_y) <= 1) {
			circle_points++;
		}
		square_points++;
	}

	double pi = (double)(4.0*circle_points)/square_points;
	printf("The estimated PI is %lf in %d times\n", pi, intervals*intervals);

	pthread_exit(0);  // the thread finish normally or abnormally.
}

int main(int argc, char const *argv[])
{
	clock_t start, delta;
	double time_used;
	start = clock();

	int count = 10;
	pthread_t calculate_pi_threads[count];

	int args[count];
	for (int i = 0; i<count; ++i) {
		args[i] = 1000*(i+1);
		pthread_create(calculate_pi_threads+i, NULL, calculate_pi, args+i);
	}
	for (int i = 0; i<count; ++i) {
		pthread_join(calculate_pi_threads[i], NULL);
	}
	delta = clock() - start;
	printf("The time taken: %lf seconds\n", (double)delta/CLOCKS_PER_SEC);
	return 0;
}
