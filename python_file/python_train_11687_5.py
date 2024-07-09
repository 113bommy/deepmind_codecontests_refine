T = int(input())
for _ in range(T):
	n,k,l = map(int, input().split())
	d = list(map(int, input().split()))
	ranges = []
	t = -102
	co = 0
	for i in range(n):
		ch = [max(t+1, -l+d[i]), l-d[i]]
		t = max(-l+d[i],t+1)
		if k<=l-d[i]:
			ch = [-102,102]
			t = -101
		ranges.append(ch)
		
		
		if ranges[i][0]>ranges[i][1]:
			print("NO")
			co = 1
			break
	if co==0:
		print("YES")