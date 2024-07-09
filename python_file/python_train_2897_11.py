n = int(input())
data = [input() for i in range(n)]
ans = 0
for a in range(n):
    b = 0
    t = True
    for i in range(n):
        for j in range(n):
            if data[(i + a) % n][(j + b) % n] != data[(j + a) % n][(i + b) % n]:
                t = False
                break

    if t:
        ans += n

print(ans)