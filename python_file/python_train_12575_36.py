N = int(input())
S = input()

ans, tmp = 0, 0
for i in range(N):
    for j in range(N - i):
        if S[j] == S[i + j]:
            tmp += 1
        else:
            ans, tmp = max(ans, min(tmp, i)), 0
    ans, tmp = max(ans, min(tmp, i)), 0

print(ans)
