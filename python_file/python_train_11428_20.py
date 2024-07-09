n, x, m = map(int, input().split())
result = [x]
for i in range(m):
    y = (result[-1] * result[-1]) % m
    if y in result:
        start = result.index(y)
        end = i
        break
    result.append(y)

loop = result[start:]
a = start
b = (n - a) // len(loop)
c = (n - a) % len(loop)
ans = sum(result[:a]) + (sum(loop) * b) + sum(loop[:c])
print(ans)