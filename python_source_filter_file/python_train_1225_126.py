n,m=map(int,input.split())
l=list(map(int,input().split()))
l.sort()
print(sum(l[0:m]))