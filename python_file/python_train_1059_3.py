dp, cnt = [0], 1
dp2 = [0]
while dp[-1] <= int(1e18):
    ans = dp2[-1] + (10 ** cnt - 10 ** (cnt - 1)) * cnt
    dp2.append(ans)
    ans = dp[-1] + dp2[-2] * (10 ** cnt - 10 ** (cnt - 1)) + cnt * (10 ** cnt - 10 ** (cnt - 1) + 1) * (10 ** cnt - 10 ** (cnt - 1)) / 2
    ans = int(ans)
    cnt += 1
    dp.append(ans)
def Cal(a, b):
    return dp2[b - 1] * a + b * int(a * (a + 1) / 2)
q = int(input())
for _ in range(q):
    k = int(input())
    i = 0
    while k > dp[i]:
        i += 1
    k -= dp[i - 1]
    l, r = 0, 10 ** i - 10 ** (i - 1)
    last = int((l + r) / 2)
    while not(Cal(last, i) < k and Cal(last + 1, i) >= k):
        if(Cal(last, i) < k):
            l = last
            last = int((l + r) / 2 + 1)
        else:
            r = last
            last = int((l + r) / 2)
    k -= Cal(last, i)
    j = 0
    while dp2[j] < k:
        j += 1
    k -= dp2[j - 1]
    a = int((k - 1) / j)
    k -= a * j
    Long = str(10 ** (j - 1) + a)
    print(Long[k - 1])