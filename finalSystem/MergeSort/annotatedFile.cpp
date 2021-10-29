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
{	 for (int arbitary = 0; arbitary < 10; arbitary++) {
	//Initialise array to be sorted
cout<<"LN "<<__LINE__<<endl;clock_gettime(clockType, &start);	vector<int> vec(100000);	clock_gettime(clockType, &finish); elapsedTime(start, finish);

	//Read input file
cout<<"LN "<<__LINE__<<endl;clock_gettime(clockType, &start);	fstream input;	clock_gettime(clockType, &finish); elapsedTime(start, finish);
cout<<"LN "<<__LINE__<<endl;clock_gettime(clockType, &start);	input.open ("randOut.txt", ios::in);	clock_gettime(clockType, &finish); elapsedTime(start, finish);

cout<<"LN "<<__LINE__<<endl;clock_gettime(clockType, &start);	for (int i=0; i<100000; i++)
	{
		input>>vec[i];
	}	clock_gettime(clockType, &finish); cout<<"LN "<<__LINE__<<endl; elapsedTime(start, finish);

	//sorting algorithm: Selection Sort
cout<<"LN "<<__LINE__<<endl;clock_gettime(clockType, &start);	vec = mergesort(vec);	clock_gettime(clockType, &finish); elapsedTime(start, finish);

}	return 0;
}
