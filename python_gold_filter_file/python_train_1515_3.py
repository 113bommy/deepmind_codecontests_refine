a, b, c, d, e = sorted([int(i) for i in input().split()])
max = 0
if (d == e) & (c == d):
	if c*3 > max:
		max = c*3
if (d == b) & (c == d):
	if c*3 > max:
		max = c*3
if (a == b) & (c == a):
	if c*3 > max:
		max = c*3
if a == b:
	if b*2 > max:
		max = b*2
if c == b:
	if b*2 > max:
		max = c*2
if c == d:
	if d*2 > max:
		max = d*2
if d == e:
	if e*2 > max:
		max = e*2
print(a+b+c+d+e-max)