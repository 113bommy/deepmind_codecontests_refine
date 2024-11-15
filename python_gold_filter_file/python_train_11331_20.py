K = int(input())

def solve(K):
    if K == 0:
        return [3, 3, 3, 3]
    if K == 1:
        return [1, 0, 3]
    if K == 2:
        return [2, 2]
    if K <= 2 * 10**16 - 10:
        if K % 2 == 0:
            return [K//2 + 1, K//2 + 1]
        else:
            return [K//2, K//2 + 3]
    N, R = divmod(K, 10**16)
    if R != 0:
        N = N + 1
    if N <= 2:
        N = 3
    a = K//N
    r = K - N * a
    if r == 0:
        return [N - 1 + a] * N
    ret = [N + a] * N
    for i in range(N - r):
        ret[i] -= (N + 1)
        for j in range(N):
            ret[j] += 1
    return ret


ans = solve(K)
print(len(ans))
print(*ans)
