N = int(input())
S = list(input() for i in range(N))
ans = 0
for A in range(N):
    flag = 1
    for i in range(N):
        for j in range(N):
            if S[i][(j+A)%N] != S[j][(i+A)%N]:
                flag = 0
    ans += flag*N
print(ans)