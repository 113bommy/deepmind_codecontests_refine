number_of_lines = int(input())

lenghts = [ int(x) for x in input().split() ]

lenghts.sort()

fail = True

for i in range(3,len(lenghts),3):

	if lenghts[i] < lenghts[i-1] + lenghts[i-2]:
		print ('YES')
		fail = False
		break

if fail:
	print ('NO')