n=int(input())
su=0
a=list(map(int,input().split()))
for t in range(n):
      s=str(a[t])
      count=0
      for i in range(len(s)):
            q=ord(s[i])-ord('0')
            count=count*10 +q
            count=count*10 +q
      su+=count
      su%=998244353
su*=n
su%=998244353
print(su)
      
      
