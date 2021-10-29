/*
This program reads in a file containing 100,000 numbers
and sorts them using the merge sort algorithm
*/

#include <iostream>
#include <time.h>
#include <fstream>
#include <vector>

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

//Function to merge two vectors depeding on their elements
vector<int> merge(vector<int> vecA, vector<int> vecB)
{
	vector<int> result;

	while(vecA.size() != 0 && vecB.size() != 0)
	{
		if (vecA[0] < vecB[0])
		{
			result.push_back(vecA[0]);
			vecA.erase(vecA.begin());
		}
		else
		{
			result.push_back(vecB[0]);
			vecB.erase(vecB.begin());
		}
	}

	while(vecA.size() != 0)
	{
			result.push_back(vecA[0]);
			vecA.erase(vecA.begin());
	}

	while(vecB.size() != 0)
	{
			result.push_back(vecB[0]);
			vecB.erase(vecB.begin());
	}

	return result;
}


//Recursive merge sort function that splits the vector containing the numbers into multiple smaller vector and sorts them accordingly
vector<int> mergesort(vector<int> vec)
{
	if(vec.size() <= 1) return vec;

	vector<int> left;
	vector<int> right; 
	vector<int> result;

	int middle = vec.size()/2;

	for(int i=0; i<middle; i++)
	{
		left.push_back(vec[i]);
	}

	for(int i=middle; i<vec.size(); i++)
	{
		right.push_back(vec[i]);
	}

	left = mergesort(left);
	right = mergesort(right);

	result = merge(left,right);

	return result;
}


int 
main (void)
{	 
	//Initialise array to be sorted
	vector<int> vec(100000);

	//Read input file
	fstream input;
	input.open ("randOut.txt", ios::in);

	//Add numbers to from file to the vector
	for (int i=0; i<100000; i++)
	{
		input>>vec[i];
	}

	//Call the mergesort algorithm
	vec = mergesort(vec);

	return 0;
}