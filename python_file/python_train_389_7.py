import math

N = int(input())
A = list(map(int, input().split()))
C = [0] * (10 ** 6 + 1)

for i in range(N):
    C[A[i]] += 1

is_pairwise = True
max_a = max(A) + 1
X = [0] * max_a
for i in range(2, max_a):
    count = 0
    for j in range(i, max_a, i):
        count += C[j]
    if count > 1:
        is_pairwise = False

if is_pairwise:
    print('pairwise coprime')
    exit()

tmp = A[0]
for i in range(1, N):
    tmp = math.gcd(tmp, A[i])

if tmp == 1:
    print('setwise coprime')
else:
    print('not coprime')
