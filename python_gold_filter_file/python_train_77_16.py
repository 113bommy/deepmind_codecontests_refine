N = int(input())
S = [input() for i in range(N)]
for v in ['AC', 'WA', 'TLE', 'RE']:
	print('{0} x {1}'.format(v, S.count(v)))