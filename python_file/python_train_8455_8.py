for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    c=[[0 for i in range(n)]]
    for i in range(1,27):
        k=[]
        if a[0]==i:
            k.append(1)
            count=1
        else:
            k.append(0)
            count=0
        for j in range(1,n):
            if a[j]==i:
                count+=1
            k.append(count)
        c.append(k[:])
    maxx=0
    for i in range(1,27):
        maxxi=0
        for j in range(1,27):
            count=c[j][n-1]
            if count==0 or c[i][n-1]==0:
                continue
            else:
                for pi in range(0,n):
                    if a[pi]==i:
                        break
                for pj in range(n-1,-1,-1):
                    if a[pj]==i:
                        break
                nu=2
                while (pj-pi)>1:
                    count=max(count,nu+c[j][pj-1]-c[j][pi])
                    for o in range(pi+1,pj):
                        if a[o]==i:
                            break
                    pi=o
                    for o in range(pj-1,pi,-1):
                        if a[o]==i:
                            break
                    pj=o
                    nu+=2
            maxxi=max(maxxi,count)
        maxx=max(maxx,maxxi)
    print(maxx)