N,K = map(int,input().split()) 
A = [int(i)-1 for i in input().split()]
now = 0

while K:
    if K % 2: 
        now = A[now]
    tmp = A[:]
    for i in range(N):
        tmp[i] = A[A[i]]
    A = tmp[:]
    K //= 2
print(now + 1)