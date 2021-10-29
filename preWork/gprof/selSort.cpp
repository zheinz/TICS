#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

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
	int start;
	int temp;
	int min;

	for(int i=0; i<100000-1;i++)
	{
		start = vec[i];
		min = i;

		for(int j=i+1; j<100000; j++)
		{
			if(vec[j] < vec[min])
			{
				min = j;
			} 
		}

		temp = start;
		vec[i] = vec[min];
		vec[min] = temp;
	}


	//Create file for output
	fstream output;
	output.open("selSortOut.txt", ios::out);
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