n,m = list(map(int, input().split()))

a = m//n

for i in range(1, a+1)[::-1]:
    if m%i == 0:
        break

print(i)