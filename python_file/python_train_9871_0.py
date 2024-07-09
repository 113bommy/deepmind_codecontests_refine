def main():
    import sys
    input=sys.stdin.buffer.readline
    n=int(input())+1
    dp=[0]*n*2
    for h,a in zip(map(int,input().split()),map(int,input().split())):
        l,r,s=n,h+n,0
        while l<r:
            if l&1:
                t=dp[l]
                if t>s:s=t
                l+=1
            if r&1:
                r-=1
                t=dp[r]
                if t>s:s=t
            l>>=1
            r>>=1
        s+=a
        i=h+n
        if s>dp[i]:
            dp[i]=s
            i>>=1
            while i:
                s,t=dp[i+i],dp[i-~i]
                if t>s:s=t
                if s>dp[i]:dp[i]=s
                else:break
                i>>=1
    print(dp[1])
main()