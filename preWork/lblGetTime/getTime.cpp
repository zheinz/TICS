#include <iostream>
#include <time.h>

using namespace std;

auto clockType = CLOCK_THREAD_CPUTIME_ID;
struct timespec start, finish, t1, t2;

void elapsedTime(timespec start, timespec finish)
{
	long seconds = finish.tv_sec - start.tv_sec;
	long nanoseconds = finish.tv_nsec - start.tv_nsec;

	cout<<seconds*1e9+nanoseconds<<" ";
}


int main(void)
{
for(int loop=0; loop<1000000; loop++)
{
	clock_gettime(clockType, &start);
	int * array = new int[100];
	clock_gettime(clockType, &finish);
	elapsedTime(start, finish);

	clock_gettime(clockType, &start);
	*(array + 50) = 50;
	clock_gettime(clockType, &finish);
	elapsedTime(start, finish);

	clock_gettime(clockType, &start);
	delete[] array;
	clock_gettime(clockType, &finish);
	elapsedTime(start, finish);

	clock_gettime(clockType, &start);
	int array2[100] = {};
	clock_gettime(clockType, &finish);
	elapsedTime(start, finish);

	clock_gettime(clockType, &start);
	array[50] = 50;
	clock_gettime(clockType, &finish);
	elapsedTime(start, finish);

	clock_gettime(clockType, &start);
	int i = 5;
	clock_gettime(clockType, &finish);
	elapsedTime(start, finish);

	clock_gettime(clockType, &start);
	i = 97;
	clock_gettime(clockType, &finish);
	elapsedTime(start, finish);

	clock_gettime(clockType, &start);
	char c = 'z';
	clock_gettime(clockType, &finish);
	elapsedTime(start, finish);

	clock_gettime(clockType, &start);
	c = 'a';
	clock_gettime(clockType, &finish);
	elapsedTime(start, finish);

	clock_gettime(clockType, &start);
	string str = "Hello World";
	clock_gettime(clockType, &finish);
	elapsedTime(start, finish);

	clock_gettime(clockType, &start);
	str = "Goodbye World";
	clock_gettime(clockType, &finish);
	elapsedTime(start, finish);

	clock_gettime(clockType, &start);
	bool cond = true;
	clock_gettime(clockType, &finish);
	elapsedTime(start, finish);

	clock_gettime(clockType, &start);
	if(cond) {}
	clock_gettime(clockType, &finish);
	elapsedTime(start, finish);

	clock_gettime(clockType, &start);
	cond = false;
	clock_gettime(clockType, &finish);
	elapsedTime(start, finish);

	clock_gettime(clockType, &start);
	if(cond) {}
	clock_gettime(clockType, &finish);
	elapsedTime(start, finish);

	clock_gettime(clockType, &start);
	if(i < c) {}
	clock_gettime(clockType, &finish);
	elapsedTime(start, finish);

	clock_gettime(clockType, &start);
	if(i == c) {}
	clock_gettime(clockType, &finish);
	elapsedTime(start, finish);

	clock_gettime(clockType, &start);
	if(i > c) {}
	clock_gettime(clockType, &finish);
	elapsedTime(start, finish);

	clock_gettime(clockType, &start);
	if(i == 97 && c == 'a') {}
	clock_gettime(clockType, &finish);
	elapsedTime(start, finish);

	clock_gettime(clockType, &start);
	if(i == 97 || c == 'a') {}
	clock_gettime(clockType, &finish);
	elapsedTime(start, finish);

	clock_gettime(clockType, &start);
	if(i == 97 && c == 'b') {}
	clock_gettime(clockType, &finish);
	elapsedTime(start, finish);

	clock_gettime(clockType, &start);
	if(i == 97 || c == 'b') {}
	clock_gettime(clockType, &finish);
	elapsedTime(start, finish);

	clock_gettime(clockType, &start);
	if(i == 100 && c == 'a') {}
	clock_gettime(clockType, &finish);
	elapsedTime(start, finish);

	clock_gettime(clockType, &start);
	if(i == 100 || c == 'a') {}
	clock_gettime(clockType, &finish);
	elapsedTime(start, finish);

	clock_gettime(clockType, &start);
	if(i == 100 && c == 'b') {}
	clock_gettime(clockType, &finish);
	elapsedTime(start, finish);

	clock_gettime(clockType, &start);
	if(i == 100 || c == 'b') {}
	clock_gettime(clockType, &finish);
	elapsedTime(start, finish);

	cout<<endl;
}

	return 0;
}
	
			

	
	
	

	
	


	


		
	


		
	


		
	

	
	


		
	


