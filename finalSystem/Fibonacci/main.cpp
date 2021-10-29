/*
This program calculates the 5 element in the fibonacci sequence 
and output the result
*/

#include <iostream>
#include <time.h>

using namespace std;

auto clockType = CLOCK_PROCESS_CPUTIME_ID;
struct timespec start, finish, t1, t2;

void elapsedTime(timespec start, timespec finish)
{
  long seconds = finish.tv_sec - start.tv_sec;
  long nanoseconds = finish.tv_nsec - start.tv_nsec;

  std::cout<<seconds*1e9+nanoseconds;
  std::cout<<" nanoseconds"<<std::endl;
}

//Recursive fibonacci function
int fibonacci (int n)
{
	if (n <= 1) return n;

	return fibonacci(n-1) + fibonacci(n-2);
}

int 
main (void)
{

	int result = fibonacci(5);
	cout<<result<<endl;

	return 0;
}
	
			

	
	
	

	
	