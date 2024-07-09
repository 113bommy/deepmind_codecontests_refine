import bisect

N = int(input())
L = sorted(list(map(int, input().split())))

ans = 0
for i in range(N):
    for j in range(i + 1, N):
        ans += bisect.bisect_left(L[j + 1:], L[i] + L[j])

print(ans)
