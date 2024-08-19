// C Program to Illustrate the use of clock() Function
#include <math.h>
#include <stdio.h>
#include <time.h>

int main()
{
	float a;
	clock_t time_req;

	// Without using pow function
	time_req = clock();
	for (int i = 0; i < 200000; i++) {
		a = log(i * i * i * i);
	}
	time_req = clock() - time_req;
	printf("Processor time taken for multiplication: %f "
		"seconds\n",
		(float)time_req / CLOCKS_PER_SEC);

	// Using pow function
	time_req = clock();
	for (int i = 0; i < 200000; i++) {
		a = log(pow(i, 4));
	}
	time_req = clock() - time_req;
	printf("Processor time taken in pow function: %f "
		"seconds\n",
		(float)time_req / CLOCKS_PER_SEC);

	return 0;
}
