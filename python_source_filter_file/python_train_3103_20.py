N = int(input())
W = map(int,input().split())
L = []
for i in range(1,N):
  L.append(abs(sum(N[:i])-sum(N[i:])))
print(min(L))