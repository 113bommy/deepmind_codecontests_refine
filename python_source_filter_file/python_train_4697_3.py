l=list(map(int,input().split()))
l.sort()
print(max(0,l[0]-(l[1]+l[2]-1)))