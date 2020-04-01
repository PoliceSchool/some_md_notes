#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>

int intervals = 20000;

int main(int argc, char const *argv[])
{
	clock_t start, delta;
	double time_used;

	start = clock();

	srand(time(NULL));

	int circle_points = 0;
	int square_points = 0;
	double pi;

	for (int i = 0; i<intervals*intervals; ++i) {
		double rand_x = (double)rand()/RAND_MAX;
		double rand_y = (double)rand()/RAND_MAX;

		if ((rand_x*rand_x + rand_y*rand_y) <= 1) {
			circle_points++;
		}
		square_points++;
	}

	pi = (double)(4.0*circle_points)/square_points;
	printf("circle points:%d, square_points:%d, The estimated PI is %lf\n", circle_points, square_points, pi);
	delta = clock() - start;
	printf("The time taken: %lf seconds\n", (double)delta/CLOCKS_PER_SEC);
	return 0;
}
