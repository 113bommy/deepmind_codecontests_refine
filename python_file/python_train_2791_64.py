N, K = map(int, input().split())
h = list(map(int, input().split()))
c = [0]*N
for i in range(1, N):
    c[i] = min([c[j] + abs(h[i]-h[j]) for j in range(max(0, i-K), i)])
print(c[N-1])