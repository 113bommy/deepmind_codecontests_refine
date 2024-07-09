n,k = map(int,input().split())
m =1
for i in range(k//n+1)[::-1]:
    if k%i==0 and k//i>=n:
        m= i
        break
print(m)