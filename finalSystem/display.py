"""
Reads in the files created by analyse.py and displays them according to the desired output shown in the final paper
"""

#Open the file containing output from host execution and add it to a new list
import sys 

host = open(sys.argv[1], "r")

hostTimes = []
for i in host:
	hostTimes.append(i.strip("\n"))
hostTimes.pop()

host.close()


#Open the file containing the output from QEMU execution and add it to a new list
qemu = open(sys.argv[2], "r")

qemuTimes = []
for i in qemu:
	qemuTimes.append(i.strip("\n"))
qemuTimes.pop()

qemu.close()

#Calculate the percentage change and print the results based on the format shown in the final report
print("Line No:\tHost Time:\tQemu Time:\tDifference:")
for i in range(len(hostTimes)):
	print("{}\t\t{}\t\t{}\t\t{}".format(hostTimes[i].split()[1].strip(":"), hostTimes[i].split()[2], qemuTimes[i].split()[2], (((float(qemuTimes[i].split()[2])-float(hostTimes[i].split()[2]))/float(hostTimes[i].split()[2])*100))))
