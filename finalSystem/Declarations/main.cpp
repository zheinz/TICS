/*
This program performs a series of random statements including variables declarations and initialisations
variable assignments, conditonal statements and for loops
*/

#include <iostream>
#include <vector>
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

int 
main (void)
{
	int * array = new int[10];

	*(array + 5) = 50;

	delete[] array;

	int array2[10] = {};

	array[5] = 50;

	int i = 25;

	i = 0;

	vector<int> vec = {1,2,3,4,5,6,7,8,9,10};

	char c = 'z';

	c = 'a';

	double d = 23.45;

	d = 76.56;

	int array2d [2][5] = {
		{1,2,3,4,5},
		{6,7,8,9,10}
	};

	array2d [0][3] = 100;

	string str = "HelloWorld";

	cout<<str<<endl;

	str = "WorldHello";

	cout<<str<<endl;

	bool cond = true;

	if (cond) {cout<<"test"<<endl;}

	cond = false;

	for (int loop=0; loop<10; loop++)
	{
		i++;
	}

	while (i<20)
	{
		i++;
	}

	return 0;
}
	
			

	
	
	

	
	