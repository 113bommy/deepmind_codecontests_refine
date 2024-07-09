N, K = map(int,input().split())
A = list(map(int,input().split()))
F = list(map(int,input().split()))

A.sort()
F.sort(reverse = True)

def solve(n):
    cnt = 0
    for i in range(N):
        cnt += max(0, A[i] - n // F[i])
    return cnt <= K

left = -1
right = 10 ** 12 + 1

while left + 1 < right:
    mid = (left + right) // 2
    if solve(mid):
        right = mid
    else:
        left = mid

print(right)