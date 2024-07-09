import sys
from bisect import bisect
from itertools import accumulate

n, t = map(int, input().split())
constant = []
variable = []
for line in sys.stdin:
    a, b = map(int, line.split())
    if a == 0:
        constant.append(b + 1)
    else:
        variable.append((a / (b + 1), a, b))
constant.sort()
variable.sort(reverse=True)
INF = 10 ** 10
t += 1
t2 = t.bit_length() + 1
# dp[j]: (i番目まで見て) j件の店で買い物を完了した時の、次の店に到着できる最短時間
dp = [INF] * t2
dp[0] = 1
for _, a, b in variable:
    for j in range(t2 - 1, -1, -1):
        if dp[j] == INF:
            continue
        tmp = (a + 1) * dp[j] + b + 1
        if tmp > t:
            continue
        if dp[j + 1] > tmp:
            dp[j + 1] = tmp

const_acc = list(accumulate(constant))
ans = 0

for i, c in enumerate(dp):
    if c == INF:
        break
    remaining = t - c
    k = bisect(const_acc, remaining)
    ans = max(ans, i + k)

print(ans)
