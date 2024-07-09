#023_B
n = int(input())
s = [input() * 2 for _ in range(n)]
ans = 0
for b in range(0, n):
    flg = True
    for i in range(n):
        for j in range(n):
            if s[i][b+j] != s[j][b+i]:
                flg = False
                break
    if flg:
        ans += 1

print(ans * n)