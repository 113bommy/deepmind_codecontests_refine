n = int(input())
S = list(input())
ans = S.count('.')
c = ans
for i in range(n):
    if (S[i] == '#'):
        c += 1
    else:
        c -= 1
    ans = min(ans, c)


print(ans)