N,M=map(int,input().split())
h=list(map(int,input().split()))
t=[0]*N
for i in range(M):
    A,B=map(int,input().split())
    t[A-1] = max(t[A-1], h[B-1])
    t[B-1] = max(t[B-1], h[A-1])

ct=0
for j in range(N):
    if h[j]>t[j]:
        ct+=1
print(ct)
