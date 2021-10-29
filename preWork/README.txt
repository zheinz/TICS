googlePerf:
	Contains results gathered from using the google perf profiling tools. The merSort and Selsort cpp files are source code representing a merge sort
	algorithm and selection sort algorithm and were compiled into executables to be run on the host architecture, in qemu-system emulation and qemu-user mode.
	These executions were then profiled using googlePerf tools.
	
	Naming Conventions & Files:
		.prof files are profiles collected by googlePerfTools
		.pdf are images of call graphs created from the profiles
		.cpp source code files
		.txt input and output files used in the executables
	
		Profiles collected on host execution are named as
			"filename".prof	e.g.	"merSort.prof"
			
		Profiles collected on qemu-system execution are named as
			"filename"Sys.prof	e.g.	"merSortSys.prof"
		
		Profiles collected on qemu-user execution are named as
			"filename"User.prof	e.g.	"merSortUser.prof"
		

gprof:
	Contains results gathered from using the gprof tool. The merSort and Selsort cpp files are source code representing a merge sort algorithm and 
	selection sort algorithm and were compiled into executables to be run on the host architecture, in qemu-system emulation and qemu-user mode. 
	These executions were then profiled using gprof tools.
	
	Naming Conventions & Files:
		.cpp source code files
		.txt are either input files or profiles collected by gprof
		
		Profiles collected on host execution are named as
			"filename".txt	e.g.	"merSort.txt"
			
		Profiles collected on qemu-system execution are named as
			"filename"Sys.txt	e.g.	"merSortSys.txt"
		
		Profiles collected on qemu-user execution are named as
			"filename"User.txt	e.g.	"merSortUser.txt"


perf:
	Contains results gathered from using the Linux perf tool. The merSort and Selsort cpp files are source code representing a merge sort algorithm and 
	selection sort algorithm and were compiled into executables to be run on the host architecture, in qemu-system emulation and qemu-user mode. 
	These executions were then profiled using the Linux perf tool.
	
	Naming Conventions & Files:
		.cpp source code files
		.txt are either input files or output files used in the executables
		.svg are flame graphs that follow the same naming conventions as the profiles
		.data files are profiles collected by perf
		out.Folded files were files used to generate the flame graphs and follow the same naming convention as the profiles
		
		Profiles collected on host execution are named as
			"filename".txt	e.g.	"merSort.txt"
			
		Profiles collected on qemu-system execution are named as
			"filename"Sys.txt	e.g.	"merSortSys.txt"
		
		Profiles collected on qemu-user execution are named as
			"filename"User.txt	e.g.	"merSortUser.txt"


lblGetTime:
	Contains results gathered from instrumentating the code using system calls. The python script analyses the output from the getTime.cpp file and 
	the sub directory double repeats the collection multiple times for better results
	
	Naming Conventions & Files:
		.cpp are source code files
		.py are python scripts used for analysing and manipualting the data 
		.txt are files used to store input and ouput from the executables for the python scripts
		.html are line graphs produced by the python scripts as part of the analysis
		.sh are bash scripts used to automate the process
		

