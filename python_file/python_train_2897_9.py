N = int(input())
S = [list(input()) for _ in range(N)]

def generate(A, B):
    T = [[""] * N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            ni = (i + A) % N
            nj = (j + B) % N
            T[ni][nj] = S[i][j]
    flag = True
    for i in range(N):
        for j in range(N):
            flag &= T[i][j] == T[j][i]
    return flag

ans = 0

for A in range(N):
    ans += N * generate(A, 0)

print(ans)