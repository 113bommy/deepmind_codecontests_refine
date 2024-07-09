n = int(input())
s = list(map(int, list(input())))
ans = 0
for i in range(1000):
    c = 0
    for j in s:
        if i % 10 == j:
            if c == 2:
                ans += 1
                break
            c += 1
            i //= 10
print(ans)