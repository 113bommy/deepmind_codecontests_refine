n = int(input())
m = n//2
print(m)
for i in range(1,m+1):
    print(1, i)
for i in range(m+1,n+1):
    print(i-m+1, m)