n,k=map(int,input().split())
d=list()
array=list()
for i in range(k):
	d.extend(input())
	array.extend(input().split())

print(n-len(set(array)))