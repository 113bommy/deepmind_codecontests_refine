n,k=map(int,input().split())
h=list(map(int,input().split()))

h.sort(reverse=True)
del h[0:k]
print(sum(h))