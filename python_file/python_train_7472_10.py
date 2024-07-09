n = int(input())
ara = [input() for _ in range(n)]
pref = []
suff = []

for s in ara:
	pos = neg = 0
	for ch in s:
		if ch == '(':
			pos += 1
		elif pos == 0:
			neg += 1
		else:
			pos -= 1
	if pos >= neg:
		pref.append([pos, neg])
	else:
		suff.append([pos, neg])


pref.sort(key=lambda x: x[1])
suff.sort(key=lambda x: x[0], reverse=True)

totPos = 0

ara = pref + suff

for pos, neg in ara:
	if neg > totPos:
		print("No")
		exit(0)
	totPos -= neg
	totPos += pos


if totPos != 0:
	print("No")
else:
	print("Yes")
