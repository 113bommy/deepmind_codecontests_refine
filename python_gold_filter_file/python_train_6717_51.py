n=int(input())
cnt=2
for i in range(2,n+1):
    cnt+=2**i
print(cnt)