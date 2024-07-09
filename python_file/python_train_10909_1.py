N = int(input())
S = input()

ans = 0
for n in range(1000):
    n = str(n).zfill(3)
    i = 0
    for j in range(N):
        if S[j] == n[i]:
            i += 1
            if i == 3:
                ans += 1
                break

print(ans)
