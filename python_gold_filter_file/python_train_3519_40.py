N, K = map(int, input().split())
V = list(map(int, input().split()))
U = V[::-1]
ret = 0

m = min(N, K)
for l in range(m+1):
    for r in range(m+1-l):
        hold = V[:l] + U[:r]
        hold.sort()
        for d in range(K+1-l-r):
            ret = max(ret, sum(hold[d:]))

print(ret)