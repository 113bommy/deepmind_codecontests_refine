N, K = map(int, input().split())
A = list(map(int, input().split()))
c = [0]*N

for _ in range(min(K, 100)):
    b = [0]*(N+1)
    for i, a in enumerate(A):
        b[max(i-a, 0)] += 1
        b[min(i+a+1, N)] -= 1
    
    x = 0
    for i in range(N):
        x += b[i]
        A[i] = x

print(" ".join(str(a) for a in A))