"""
This file takes in a file containing the output from running the instrumentated executable in either QEMU or on the host architecture 
and inserts it into a dataframe which is printed
"""

import sys 

#Open the file and add each line that contains output resulting from the instrumentaion to a list
outputFile = open(sys.argv[1], 'r')
output = []
for i in outputFile:
	if "LN" in i or "nanoseconds" in i:
		output.append(i.strip("\n"))
	else:
		continue

#Create two empty lists to store the lines that were instrumented and their corrosponding times
lines = []
times = []

#Loop through the ouput and add all the line numbers to the line list and the timings to the time list 
index = 0
for i in range(len(output)):
	if "LN" in output[i] and "LN" in output[i-1]:
		continue
	elif "LN" in output[i]:
		if "LN" in output[i+1]:
			lines.append("Line {}-{}:".format(output[i].replace("LN ",""), output[i+1].replace("LN ","")))
		else:
			lines.append("Line {}:".format(output[i].replace("LN ","")))
	else:
		times.append(output[i].replace(" nanoseconds", ""))


#Remove any duplicate lines
lines = list(dict.fromkeys(lines))

#Initialise a loop variable depending on the number of instrumented lines and recorded times and an empty list to contain the rows for the dataframe
loop = int(len(times)/len(lines))
rows = []

#loop through the lines and times and create rows to be used in the dataframe
index = 0
for i in range(loop):
	row = []
	for j in range(len(lines)):
		row.append(times[index])
		index+=1
	rows.append(row)

#Import pandas and create a dataframe using the rows above
import pandas as pd

df = pd.DataFrame(rows,columns = lines).astype(float)
df = df.iloc[5:].reset_index(drop=True)

print(df.mean())
