a,b,c=map(int, input().split(" "))
count=0
for i in range(a,b):
	if c%i==0:
		count += 1
print(count)