n = int(input())
s = input()
c1, c2, res = 'a', 'a', ['']*n
for i in range(n):
	if s[i] >= c1:
		res[i] = '0'
		c1 = s[i]
	elif s[i] >= c2:
		res[i] = '1'
		c2 = s[i]
	else:
		print('NO')
		break
else:
	print('YES')
	print(''.join(res))
