n, m = map(int, input().split())
print(min(n, m)+1)
for i in range(min(n, m)+1):
    print(i, m-i)
