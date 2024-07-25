#include <stdio.h>

int add(int a, int b)
{

	for (int i = 1; i <= b; i++)
		a++;
	return a;
}

int main()
{

	int a = add(10, 32);
	printf("%d", a);
	return 0;
}


