n=int(input())
p=sorted(map(int,input().split()))
print(min(sum(abs(x-i)for x,i in zip(p,range(s,n+1,2)))for s in(1,2)))
