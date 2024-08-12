// C program to show function
// call and definition
#include <stdio.h>

// Function that takes two parameters
// a and b as inputs and returns
// their sum
int sum(int a, int b)
{
  return a + b;
}

// Driver code
int main()
{
  // Calling sum function and
  // storing its value in add variable
  int add = sum(10, 30);

  printf("Sum is: %d", add);
  return 0;
}
