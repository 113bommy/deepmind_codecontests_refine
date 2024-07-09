def main():
    from itertools import accumulate as ac
    n,k=map(int,input().split())
    kk=2*k
    xyc=[input().split() for _ in [0]*n]
    b=[[0]*(k+1) for _ in [0]*(kk+1)]
    for x,y,c in xyc:
        if c=="B":
            if int(y)%kk<k:
                b[int(x)%kk+1][int(y)%k+1]+=1
            else:
                b[(int(x)+k)%kk+1][int(y)%k+1]+=1
        else:
            if int(y)%kk<k:
                b[(int(x)+k)%kk+1][int(y)%k+1]+=1
            else:
                b[int(x)%kk+1][int(y)%k+1]+=1
    b=[list(ac(i)) for i in b]
    for i in range(1,kk+1):
        for j in range(k+1):
            b[i][j]+=b[i-1][j]
    ans=0
    for i in range(kk):
        if i==0:
            a_t=((i,i+k,0),(i+k,kk,1))
        elif i<k:
            a_t=((0,i,-1),(i,i+k,0),(i+k,kk,1))
        elif i==k:
            a_t=((0,i,-1),(i,kk,0))
        else:
            a_t=((0,i-k,-2),(i-k,i,-1),(i,kk,0))
        for j in range(k):
            if j==0:
                b_t=((0,k,0),)
            else:
                b_t=((0,j,-1),(j,k,0))
            black=[]
            for i,j,l in a_t:
                for x,y,z in b_t:
                    if (l+z)%2==0:
                        black.append((i,x,j,y))
            ret=0
            for tx1,ty1,tx2,ty2 in black:
                ret+=b[tx1][ty1]+b[tx2][ty2]-b[tx1][ty2]-b[tx2][ty1]
            ans=max(ans,ret)
    print(ans)
main()
