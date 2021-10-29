import pandas as pd

hostData = pd.read_csv('host.txt', delimiter=" ", names=['Heap array dec','Heap array assign','Heap array del','Static array dec', 'Static array assign', 'Int dec',
'Int assign', 'Char dec', 'Char assign', 'String dec', 'String assign', 'Bool dec', 'If true', 'Bool assign', 'If false', 'If lt', 'If equal',
'If gt', 'And RR', 'Or RR', 'AND RW', 'OR RW', 'AND WR', 'OR WR', 'AND WW', 'OR WW', 'EMPTY']).rename_axis('Loop')

qemuData = pd.read_csv('qemu.txt', delimiter=" ", names=['Heap array dec','Heap array assign','Heap array del','Static array dec', 'Static array assign', 'Int dec',
'Int assign', 'Char dec', 'Char assign', 'String dec', 'String assign', 'Bool dec', 'If true', 'Bool assign', 'If false', 'If lt', 'If equal',
'If gt', 'And RR', 'Or RR', 'AND RW', 'OR RW', 'AND WR', 'OR WR', 'AND WW', 'OR WW', 'EMPTY']).rename_axis('Loop')

hostDataFiltered = hostData.drop([0,1,2,3,4]).reset_index(drop=True).rename_axis('Loop')
qemuDataFiltered = qemuData.drop([0,1,2,3,4]).reset_index(drop=True).rename_axis('Loop')

averageHostFiltered = hostDataFiltered.mean()
averageQemuFiltered = qemuDataFiltered.mean()

percentage = []

for x in range(26):
	percentage.append(((averageQemuFiltered[x] - averageHostFiltered[x])/averageHostFiltered[x])*100)

print(*percentage)
