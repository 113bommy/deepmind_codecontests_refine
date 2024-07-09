N, Q = map(int, input().split())
pNode = [1] * N
c = [0] * N
for i in range(N-1):
    a, b = map(int, input().split())
    pNode[b-1] = a-1
for i in range(Q):
    p, x = map(int, input().split())
    c[p-1] += x
for i in range(1, N):
    c[i] += c[pNode[i]]
print(*c)