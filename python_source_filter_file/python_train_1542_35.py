n = int(input())
*A, = map(int, input().split())
B = [0]*n
for i in range(n-1, -1, -1):
    B[i] = (sum(B[i::(i+1)])%2+A[i])%2
print(sum(B))
print(*[i for i, b in enumerate(set(B)) if b == 1])