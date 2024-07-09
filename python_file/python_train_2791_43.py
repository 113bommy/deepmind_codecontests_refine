N,K=(int(i) for i in input().split())
h = [int(i) for i in input().split()]
c = [0]*N
for i in range(1,N):
    jumpmax = min(i,K)
    c[i] = min([abs(h[i]-h[i-j])+c[i-j] for j in range(1,jumpmax+1)])
print(c[N-1])