A,B,N=map(int,input().split())
x=min(A-1,N)
print(int(A*x/B)-A*int(x/B))