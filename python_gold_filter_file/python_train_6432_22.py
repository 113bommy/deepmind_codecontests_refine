n = int(input())
x = list(map(int, input().split()))

res = 0

r = round(sum(x)/len(x))
for i in x:
    res += (i-r)**2
print(res)