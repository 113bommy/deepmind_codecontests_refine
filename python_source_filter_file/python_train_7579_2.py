n,k = map(int, input().split())
h = sorted(list(map(int, [input() for _ in range(n)])))
print(h)
print(min([h[i+k-1]-h[i] for i in range(n-k+1)]))