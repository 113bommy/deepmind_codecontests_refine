n=int(input())
k=int(input())
i=0
while i < n && 2**i<=k:
    i+=1
print(2**i+k*(n-i))
