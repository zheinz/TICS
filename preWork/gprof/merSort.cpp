#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

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


int main(void)
{	
	//Initialise array to be sorted
	vector<int> vec(100000);

	//Read input file
	fstream input;
	input.open("randOut.txt", ios::in);

	for(int i=0; i<100000; i++)
	{
		input>>vec[i];
	}

	input.close();

	//sorting algorithm: Selection Sort
	vec = mergesort(vec);


	//Create file for output
	fstream output;
	output.open("merSortOut.txt", ios::out);
	for(int i=0;i<100000;i++)
	{
		if (i==99999)
		{
			output<<vec[i];
			output.close();
			return 0;
		}
		else
		{
			output<<vec[i]<<" ";		
		}
	
	}
	return 0;
}