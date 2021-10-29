/*
This program reads in a file containing 100,000 numbers
and sorts them using the selection sort algorithm
*/

#include <iostream>
#include <time.h>
#include <fstream>
#include <vector>

using namespace std;

auto clockType = CLOCK_PROCESS_CPUTIME_ID;
struct timespec start, finish, t1, t2;

void elapsedTime (timespec start, timespec finish)
{
  long seconds = finish.tv_sec - start.tv_sec;
  long nanoseconds = finish.tv_nsec - start.tv_nsec;

  std::cout<<seconds*1e9+nanoseconds;
  std::cout<<" nanoseconds"<<std::endl;
}


int 
main (void)
{	
	//Initialise array to be sorted
	vector<int> vec(100000);

	//Read input file
	fstream input;
	input.open ("randOut.txt", ios::in);

	//Add numbers from file to the vector
	for (int i=0; i<100000; i++)
	{
		input>>vec[i];
	}

	//sorting algorithm: Selection Sort
	int begin;
	int temp;
	int min;

	for (int i=0; i<vec.size()-1;i++)
	{
		begin = vec[i];
		min = i;

		for (int j=i+1; j<vec.size(); j++)
		{
			if (vec[j] < vec[min])
			{
				min = j;
			} 
		}

		temp = begin;
		vec[i] = vec[min];
		vec[min] = temp;
	}

	return 0;
}