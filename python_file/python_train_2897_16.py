n = int(input())
s = [input() for _ in range(n)]
result = 0
for i in range(n):
    a = 1
    for x in range(n):
        if any(s[(x+i)%n][y] != s[(y+i)%n][x] for y in range(x, n)):
            a = 0
            break
    result += a
print(result*n)