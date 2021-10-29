This file explains how to navigate and execute all of experiments conducted in the final report

annotate.py:
	This file is passed a cpp source file as an argument and inserts the instrumentation at certain points in the code 
	according to the various rules setup within the python script it then output the instrumentated code to a new .cpp file
	ready for compilation and execution. 

analyse.py:
	This file takes in a file containing the output from running the instrumentated executable in either QEMU or on the host architecture 
	and inserts it into a dataframe which is then outputted to a file ready for display.py.

display.py:
	Reads in the files created by analyse.py and displays them according to the desired output shown in the final paper


Subdirectories:
	Each subdiretory corresponds to a different program as outlined in the project paper. Within each subdiretory is:
	
	--main.cpp - this includes the source code for the program. 
	
	--create.sh - a bash script that takes a source file as input using (-i) run it through annotate.py then executes 
		      it on the host and in QEMU-user and feeds this output to analyse.py and then to display.py to print the
		      results before removing an intermediate files created  during this process.
	
	--performExp.sh - runs create.sh 5 times using the main.cpp file as input and then outputs the results of the 5 executions
			   to expResults.txt
			
	--expResults.txt - contains the results from executing perform.Exp
	
	
HOW TO RUN:
	To perform the experiments shown in the paper (NOTE: Comments explaining program functionality were added after experimentation thus line numbers
	produced now will not be the same as the line numbers shown in the paper but will still point to the correct lines):
		cd into each directory individually and execute performExp.sh which will ouput the results of the 5 executions to expResults.txt which were 
		then averaged to produce the results in the report.
		For instance to execute the Declerations experiment:
			
			cd Declarations
			./performEx.sh
			
		Then you would obtain the average host time, QEMU time and percentage change for each line in the results which is what is presented 
		in the report. 
	
	
		
	To perform a single execution and comparison between the host and QEMU:
		cd into each directory individually and execute create.sh with main.cpp as input for instance once in final system folder to execute 
		declerations you would:
		
			cd Declerations
			./create.sh -i main.cpp 
	
	
		
	To instrument your own files please follow the following syntax (NOTE: INSTRUMENTATION IS NOT GUARANTEED TO WORK FOR YOUR FILES):
		- Insert the following into the cpp source file with the main function:
			#include <time.h>

			auto clockType = CLOCK_PROCESS_CPUTIME_ID;
			struct timespec start, finish, t1, t2;	

			void elapsedTime(timespec start, timespec finish)
			{
			  long seconds = finish.tv_sec - start.tv_sec;
			  long nanoseconds = finish.tv_nsec - start.tv_nsec;

			  std::cout<<seconds*1e9+nanoseconds;
			  std::cout<<" nanoseconds"<<std::endl;
			}
		
		- Ensure main is written using the syntax 
			"int 
			 main (void)
			 {
			 	//insert function body
			 }
		- Ensure loops and conditional statements have spaces between brackets
			for (cond) 
			{
				//body
			}
			
			instead of 
			
			for(cond)
			{
				//body
			}
		
		- Then use the python script and your own bash script to perform the test. 
			
		
	
