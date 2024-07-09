import sys
input = sys.stdin.readline

N=int(input())
B=[list(map(int,input().split())) for i in range(N)]

B.sort(key=lambda x:x[0]+x[1])
#W+Sの順にソートすると無駄がない。

DP=[0]*(10**4+2)
#重さの合計がWのときの価値。
#W=10**4+1ならそれ以上更新されないので、W>=10**4+1以上のものはそこに置く

for w,s,v in B:
    for i in range(s,-1,-1):
        if i+w<=10**4:
            if DP[i+w]<DP[i]+v:
                DP[i+w]=DP[i]+v

        else:
            if DP[-1]<DP[i]+v:
                DP[-1]=DP[i]+v

print(max(DP))