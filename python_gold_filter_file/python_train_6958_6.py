q,h,s,d=map(int,input().split())
n=int(input())
h=min(q*2,h)
s=min(s,h*2)
print(min(d*(n//2)+s*(n%2),s*n))