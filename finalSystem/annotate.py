"""
This file is passed a cpp source file as an argument and inserts the instrumentation at certain points in the code 
according to the various rules setup within the python script it then output the instrumentated code to a new .cpp file
ready for compilation and execution. 
"""

#Open the source code file and add all the lines to a list
import sys

originalFile = open(sys.argv[1], "r")
annotatedFile = []

for i in originalFile:
	annotatedFile.append(i.strip('\n'))

originalFile.close()


#Loop through the list containing the source code until the main function is found
i = 1
foundMain = False
while foundMain == False:
	while "main" not in annotatedFile[i]:
		i+=1
	if "main" == annotatedFile[i].split()[0]:
		foundMain = True
	else:
		i+=1


#Add for loop around the main body
i+=1
annotatedFile[i] = annotatedFile[i] + "for (int arbitary = 0; arbitary < 10; arbitary++) {"
i+=1

"""
Loop through the entire source code and add the instrumentation before and after every line depending on the following rules:
 - Time before and after a for loop, while loop or switch statment
 - Skip any comments or return statments
 - Insert instrumentation inside if, ifelse and else statements
"""
while i < len(annotatedFile):
	if '#' in annotatedFile[i] or '//' in annotatedFile[i] or '/*' in annotatedFile[i] or '*/' in annotatedFile[i]:
		i+=1

	elif annotatedFile[i] == "" or annotatedFile[i].isspace():
		i+=1

	elif "for" == annotatedFile[i].split()[0] or "while" == annotatedFile[i].split()[0] or "switch" == annotatedFile[i].split()[0]:
		if "{" in annotatedFile[i] and "}" in annotatedFile[i]:
			annotatedFile[i] = "cout<<\"LN \"<<__LINE__<<endl;;clock_gettime(clockType, &start);" + annotatedFile[i] + "\tclock_gettime(clockType, &finish); elapsedTime(start, finish);"	
			i+=1
			annotatedLines.append(i)
		elif "{" in annotatedFile[i] or "{" in annotatedFile[i+1]:
			annotatedFile[i] = "cout<<\"LN \"<<__LINE__<<endl;clock_gettime(clockType, &start);" + annotatedFile[i]
			if "{" in annotatedFile[i]:
				loopCounter = 1
				i+=1
			else:
				i+=2 
				loopCounter = 1
			while loopCounter > 0:
				if "{" in annotatedFile[i] and "}" in annotatedFile[i]:
					i+=1
				elif "{" in annotatedFile[i]:
					loopCounter+=1
					i+=1
				elif "}" in annotatedFile[i]:
					loopCounter-=1
					i+=1
				else:
					i+=1
			annotatedFile[i-1] = annotatedFile[i-1] + "\tclock_gettime(clockType, &finish); cout<<\"LN \"<<__LINE__<<endl; elapsedTime(start, finish);"	
		elif ";" in annotatedFile[i]:
			annotatedFile[i] = "cout<<\"LN \"<<__LINE__<<endl;clock_gettime(clockType, &start);" + annotatedFile[i] + "\tclock_gettime(clockType, &finish); elapsedTime(start, finish);"
			i+=1 
			annotatedLines.append(i)
		elif ";" in annotatedFile[i+1] and '{' not in annotatedFile[i]:
			annotatedFile[i] = "cout<<\"LN \"<<__LINE__<<endl;clock_gettime(clockType, &start);" + annotatedFile[i]
			i+=1
			annotatedFile[i] = annotatedFile[i] + "\tclock_gettime(clockType, &finish);cout<<\"LN \"<<__LINE__<<endl; elapsedTime(start, finish);"				
			i+=1
		else:
			i+=1

	elif "if" == annotatedFile[i].split()[0] or "else" == annotatedFile[i].split()[0] or "#ifdef" == annotatedFile[i].split()[0] or "if" == annotatedFile[i].split()[0] or "ifndef" == annotatedFile[i].split()[0]:
		if "{" in annotatedFile[i] and ";" in annotatedFile[i]:
			index = annotatedFile[i].find('{')
			index +=1
			annotatedFile[i] = annotatedFile[i][:index] + "cout<<\"LN \"<<__LINE__<<endl;clock_gettime(clockType, &start);" + annotatedFile[i][index:] +"\tclock_gettime(clockType, &finish); elapsedTime(start, finish);"		
			i+=1

		elif ";" in annotatedFile[i]:
			index = annotatedFile[i].rfind(')')
			index +=1
			annotatedFile[i] = annotatedFile[i][:index] + '{cout<<\"LN \"<<__LINE__<<endl;clock_gettime(clockType, &start);' + annotatedFile[i][index:] + "\tclock_gettime(clockType, &finish); elapsedTime(start, finish);}"
			i+=1

		elif ';' in annotatedFile[i+1] and '{' not in annotatedFile[i]:
			i+=1
			annotatedFile[i] = "{cout<<\"LN \"<<__LINE__<<endl;clock_gettime(clockType, &start);" + annotatedFile[i] + "\tclock_gettime(clockType, &finish); elapsedTime(start, finish);}"
			i+=1

		else:
			i+=1

	elif "do" == annotatedFile[i].split()[0]:
		annotatedFile[i] = "cout<<\"LN \"<<__LINE__<<endl;clock_gettime(clockType, &start);" + annotatedFile[i]
		while "while" not in annotatedFile[i]:
			i+=1
		annotatedFile[i] = annotatedFile[i] + "\tclock_gettime(clockType, &finish);cout<<\"LN \"<<__LINE__<<endl; elapsedTime(start, finish);"
		i+=1
	
	elif '}' in annotatedFile[i] and ';' not in annotatedFile[i]:
		i+=1

	elif "return" in annotatedFile[i]:
		annotatedFile[i] = "}" + annotatedFile[i]
		i+=1

	else:
		if ';' not in annotatedFile[i]:
			temp = i
			while ";" not in annotatedFile[i]:
				i+=1
			annotatedFile[temp] = "cout<<\"LN \"<<__LINE__<<endl;clock_gettime(clockType, &start);" + annotatedFile[temp]	
			annotatedFile[i] = annotatedFile[i] + "\tclock_gettime(clockType, &finish);cout<<\"LN \"<<__LINE__<<endl; elapsedTime(start, finish);"
			i+=1
		else:
			annotatedFile[i] = "cout<<\"LN \"<<__LINE__<<endl;clock_gettime(clockType, &start);" + annotatedFile[i] + "\tclock_gettime(clockType, &finish); elapsedTime(start, finish);"
			i+=1


#Write the instrumentated source code to a new file
newFile = open("annotatedFile.cpp", "w")
for i in annotatedFile:
	newFile.write("{}\n".format(i))
newFile.close()
