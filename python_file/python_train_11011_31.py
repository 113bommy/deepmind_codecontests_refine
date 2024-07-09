n, K = map(int,input().split())
A = list(map(int,input().split()))
b = [0 for _ in range(n+1)]

for _ in range(K):
    for i,a in enumerate(A):
        b[max(0, i-a)] += 1
        b[min(n, i+a+1)] -= 1

    for i in range(n):
        b[i+1] += b[i]
    A = b[:-1]
    b = [0 for _ in range(n+1)]
    if sum(A) == n*n:
        break
    
print(*A)