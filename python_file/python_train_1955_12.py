N = int(input())
A = []
P = 1000000000
for i in range(N):
    tmp = input().split(".")
    if len(tmp) == 2:
        a = int(tmp[1])
        for j in range(9-len(tmp[1])):
            a *= 10
        A.append(int(tmp[0]) * P + a)
    else:
        A.append(int(tmp[0]) * P)

div2 = [0 for i in range(N)]
div5 = [0 for i in range(N)]

for i in range(N):
    tmp = A[i]
    while tmp % 2 == 0:
        div2[i] += 1
        tmp = tmp//2
    while tmp % 5 == 0:
        div5[i] += 1
        tmp = tmp//5

cnt = [[0 for i in range(19)] for i in range(19)]

for i in range(N):
    d2 = div2[i]
    d5 = div5[i]
    if d2 > 18:
        d2 = 18
    if d5 > 18:
        d5 = 18
    cnt[d2][d5] += 1

ans = 0

for i in range(N):
    lower2 = 18 - div2[i]
    lower5 = 18 - div5[i]

    if lower2 < 0:
        lower2 = 0
    if lower5 < 0:
        lower5 = 0

    for j in range(lower2, 19):
        for k in range(lower5, 19):
            ans += cnt[j][k]

for a in A:
    if a % P == 0:
        ans -= 1

print(ans//2)
