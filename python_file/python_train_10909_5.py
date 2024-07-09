N = int(input())
S = input()

ans = 0
for i in range(1000):
    t = "{:0=3}".format(i)
    p = 0
    for j in range(N):
        if S[j] == t[p]:
            p += 1
        if p == 3:
            break
    if p == 3:
        ans += 1

print(ans)
