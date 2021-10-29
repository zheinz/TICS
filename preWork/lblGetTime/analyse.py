import pandas as pd

hostData = pd.read_csv('host.txt', delimiter=" ", names=['Heap array dec','Heap array assign','Heap array del','Static array dec', 'Static array assign', 'Int dec',
'Int assign', 'Char dec', 'Char assign', 'String dec', 'String assign', 'Bool dec', 'If true', 'Bool assign', 'If false', 'If lt', 'If equal',
'If gt', 'And RR', 'Or RR', 'AND RW', 'OR RW', 'AND WR', 'OR WR', 'AND WW', 'OR WW', 'EMPTY']).rename_axis('Loop')

qemuData = pd.read_csv('qemu.txt', delimiter=" ", names=['Heap array dec','Heap array assign','Heap array del','Static array dec', 'Static array assign', 'Int dec',
'Int assign', 'Char dec', 'Char assign', 'String dec', 'String assign', 'Bool dec', 'If true', 'Bool assign', 'If false', 'If lt', 'If equal',
'If gt', 'And RR', 'Or RR', 'AND RW', 'OR RW', 'AND WR', 'OR WR', 'AND WW', 'OR WW', 'EMPTY']).rename_axis('Loop')

print (hostData);
print (qemuData);


hostDataFiltered = hostData.drop([0,1,2,3,4]).reset_index(drop=True).rename_axis('Loop')
qemuDataFiltered = qemuData.drop([0,1,2,3,4]).reset_index(drop=True).rename_axis('Loop')

print(hostDataFiltered)
print(qemuDataFiltered)

print("\nHOST AVERAGE:")
print(hostDataFiltered.mean())
print("\n\nQEMU AVERAGE:")
print(qemuDataFiltered.mean())

averageHostFiltered = hostDataFiltered.mean()
averageQemuFiltered = qemuDataFiltered.mean()

headers = ["Heap array dec: ","Heap array assign: ","Heap array del: ","Static array dec: ", "Static array assign: ", "Int dec: \t", 
"Int assign: \t", "Char dec: \t", "Char assign: \t", "String dec: \t", "String assign: ", "Bool dec: \t", "If true: \t", "Bool assign: \t", "If false: \t", "If lt: \t\t", "If equal: \t",
"If gt: \t\t", "And RR: \t", "Or RR: \t\t", "AND RW: \t", "OR RW: \t\t", "AND WR: \t", "OR WR: \t\t", "AND WW: \t", "OR WW: \t\t"]

print("\n\nPERCENTAGE CHANGE:")
for x in range(26):
	print(headers[x], "\t", ((averageQemuFiltered[x] - averageHostFiltered[x])/averageHostFiltered[x])*100)

"""
import plotly.express as px
figHost = px.line(hostData, x=hostData.index, y=hostData.columns, markers=True, title="Host")
figHost.update_layout(xaxis_title="Loop", yaxis_title="Time (nanoseconds)", legend_title="Operation")
figHost.write_html('host.html')

figQemu = px.line(qemuData, x=qemuData.index, y=qemuData.columns, markers=True, title="QEMU")
figQemu.update_layout(xaxis_title="Loop", yaxis_title="Time (nanoseconds)", legend_title="Operation")
figQemu.write_html('qemu.html')
""" 