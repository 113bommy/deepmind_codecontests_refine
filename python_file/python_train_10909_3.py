n = int(input())
s = input()
ans = 0
for i in range(1000):
    t = str(i).zfill(3)
    ti = 0
    for j in range(n):
        if s[j] == t[ti]:
            ti += 1
            if ti == 3:
                break
    if ti == 3:
        ans += 1
print(ans)
