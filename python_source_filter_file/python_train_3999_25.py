n = int(input())
cnt = 1
prev = int(input())
for i in range(n-1):
	x = input()
	if x != prev:
		cnt+=1
		prev = x
print(cnt)