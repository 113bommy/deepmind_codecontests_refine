n = int(input())
a = list(input())
a1 = [i for i in range(n)]
new = {i : set() for i in range(n)}
flag = False
while not flag:
	flag = True
	for i in range(n - 1):
		if a[i] > a[i + 1]:
			a[i], a[i + 1] = a[i + 1], a[i]
			new.setdefault(a1[i], set()).add(a1[i + 1])
			a1[i], a1[i + 1] = a1[i + 1], a1[i]
			flag = False
i = 0
while i < n and len(new[i]) == 0:
	i += 1
if i == n:
	print("YES")
	print("0" * n)
	exit(0)
set1 = {i}
set2 = new[i]
for i in range(n):
	flag = True
	for x in new:
		flag = True
		if x in set1:
			if not len(new[x] & set1) == 0:
				flag = False
				break
			set2 |= new[x]
		elif x in set2:
			if not len(new[x] & set2) == 0:
				flag = False
				break
			set1 |= new[x]
		else:
			set1.add(x)
			set2 |= new[x]
	if not flag:
		break
if flag:
	print("YES")
	new = [0] * n
	for i in range(n):
		if i in set1:
			new[i] = 0
		else:
			new[i] = 1
	print("".join(map(str, new)))
else:
	print("NO")
