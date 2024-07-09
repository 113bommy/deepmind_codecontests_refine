N, K = map(int, input().split())
A = list(map(lambda x:int(x) - 1, input().split()))
res = list(range(N))
while K:
    if K & 1:
        res = [res[A[i]] for i in range(N)]
    A = [A[A[i]] for i in range(N)]
    K >>= 1
print(res[0] + 1)