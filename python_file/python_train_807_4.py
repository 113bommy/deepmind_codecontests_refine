N = int(input())
As = list(map(int, input().split()))
arridx = [(i, a) for i, a in enumerate(As)]
arridx.sort(key=lambda x: x[1])

dp = {}
dp[(0, N-1)] = 0
for i in range(N-1, -1, -1):
    ndp = {}
    for l in range(N-i+1):
        r = l + i - 1
        idx, a = arridx[i]
        lsc = rsc = 0
        if l > 0:
            # l-1, r から
            lsc = dp[(l-1, r)] + a * abs(l-1-idx)
        if r < N-1:
            # l, r+1 から
            rsc = dp[(l, r+1)] + a * abs(r+1-idx)
        ndp[(l, r)] = max(lsc, rsc)
    dp = ndp
print(max(dp.values()))