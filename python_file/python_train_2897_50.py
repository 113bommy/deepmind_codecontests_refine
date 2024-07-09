N = int(input())
T = [[] for i in range(N)]
for i in range(N):
    a = list(input())
    T[i] = a
num = 0
for i in range(N):
    flag = True
    for j in range(N):
        for k in range(N):
            q = k + i
            p = j + i
            if q >= N:
                q -= N
            if p >= N:
                p -= N
            if j == q:
                continue
            if T[j][q] != T[k][p]:
                flag = False

    if flag:
        num += 1

print(num * N)