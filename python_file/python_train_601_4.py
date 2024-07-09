from copy import deepcopy
mod = 10 ** 9 + 7
n, m = map(int, input().split())
s = list(map(int, input().split()))
t = list(map(int, input().split()))
ans = [1 for i in range(m + 1)]
for i in s:
    ans2 = deepcopy(ans)
    cnt = 0
    for j in range(m):
        ans2[j] = (cnt + ans2[j]) % mod
        if i == t[j]:
            cnt = (cnt + ans[j]) % mod
    ans2[-1] = (cnt+ ans2[-1]) % mod
    ans = deepcopy(ans2)
print(ans[-1])