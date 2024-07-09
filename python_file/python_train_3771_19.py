from sys import stdin
input=stdin.readline
#import bisect
#i = bisect.bisect_left(a, k)
#list=input().split(maxsplit=1)
for xoxo in range(1):
    n=int(input()) 
    s=input()
    a=[]
    b=[]
    c=[0]*26
    d=[]
    for i in range(26):
        a.append([])
        b.append([])
        d.append([])
    for i in range(n):
        #print(s[i],ord(s[i]))
        c[ord(s[i])-97]+=1
    for i in range(n):
        kk=0
        for j in range(ord(s[i])-97):
            kk+=c[j]
        a[ord(s[i])-97].append(i+kk)
        d[ord(s[i])-97].append(i)
        c[ord(s[i])-97]-=1
    s2=sorted(s)
    s1=""
    for i in range(1,n+1):
        s1+=s2[i]
    for i in range(n):
        b[ord(s1[i])-97].append(i)
    
    ans=[-1]*n    
    flag=0
    #print(a)
    #print(b)
    for i in range(26):
        if flag==1:
            break
        for j in range(len(a[i])):
            if flag==1:
                break
            if b[i][j]>=a[i][j]:
                continue
            else:
                if ans[d[i][j]]!=0:
                    ans[d[i][j]]=1
                else:
                    flag=1
                    break
                p=ans[d[i][j]]
                    
                for k in range(d[i][j]-1,d[i][j]-1-(a[i][j]-b[i][j]),-1):
                    if i>=ord(s[k])-97:
                        continue
                    else:
                        if ans[k]==-1 :
                            ans[k]=((p+1)%2)
                        if ans[k]==p :
                            flag=1
                            break
    if flag==1:
        print('NO')
    else:
        print('YES')
        for i in range(n):
            if ans[i]==-1:
                ans[i]=0
            print(ans[i],end="")