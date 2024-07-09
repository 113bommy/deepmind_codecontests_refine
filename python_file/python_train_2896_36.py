N, K = map(int, input().split())
a_list = [int(i) for i in input().split()]
A = [0, a_list[0]]
for i in range(1, N):
    A.append(A[-1] + a_list[i])
A_combination = []
for i in range(N + 1):
    for j in range(i + 1, N + 1):
        A_combination.append(A[j] - A[i])
x = 0
for i in range(40, 0, - 1):
    cnt = 0
    t = pow(2, i - 1)
    for A_i in A_combination:
        if ((x + t) & (A_i)) == (x + t):
            cnt += 1
        if cnt >= K:
            x += t
            break
print(x)