n=int(input())
l=[int(x) for x in input().split()]
l.sort()
print(l[(n-1)//2])