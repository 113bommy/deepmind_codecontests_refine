import collections
import math
from heapq import *
for t in range(int(input())):
    n,m=map(int,input().split())
    mat=[]
    ans=[]
    for i in range(n):
        s=list(input())
        s=list(map(int,s))
        mat.append(s)
    def cal(r,c):
        count=mat[r][c]+mat[r+1][c]+mat[r][c+1]+mat[r+1][c+1]
        if count==4:
            mat[r][c]=mat[r+1][c]=mat[r][c+1]=0
            ans.append([r+1,c+1,r+2,c+1,r+1,c+2])
            count=1
        if count==3:
            temp=[]
            for x,y in [(r,c),(r+1,c),(r,c+1),(r+1,c+1)]:
                if mat[x][y]==1:
                    temp.append(x+1)
                    temp.append(y+1)
            ans.append(temp)
        if count==1:
            if mat[r][c]==1 or mat[r+1][c+1]:
                if mat[r][c]==1:
                    ans.append([r+1,c+1,r+2,c+1,r+1,c+2])
                else:
                    ans.append([r+2,c+2,r+2,c+1,r+1,c+2])
                mat[r][c]=mat[r+1][c+1]=0
                mat[r+1][c]=mat[r][c+1]=1
            else:
                if mat[r+1][c]==1:
                    ans.append([r+2,c+1,r+1,c+1,r+2,c+2])
                else:
                    ans.append([r+1,c+2,r+1,c+1,r+2,c+2])
                mat[r+1][c]=mat[r][c+1]=0
                mat[r][c]=mat[r+1][c+1]=1
            count=2
        if count==2:
            if mat[r][c]==1 and mat[r+1][c+1]==1:
                ans.append([r+1,c+1,r+2,c+1,r+1,c+2])
                ans.append([r+2,c+2,r+2,c+1,r+1,c+2])
            elif mat[r][c+1]==mat[r+1][c]==1:
                ans.append([r+1,c+1,r+2,c+1,r+2,c+2])
                ans.append([r+1,c+1,r+1,c+2,r+2,c+2])
            else:
                one=[]
                zero=[]
                for x,y in [(r,c),(r+1,c),(r,c+1),(r+1,c+1)]:
                    if mat[x][y]==1:
                        one.append(x+1)
                        one.append(y+1)
                    else:
                        zero.append(x+1)
                        zero.append(y+1)
                ans.append([one[0],one[1]]+zero)
                ans.append([one[2],one[3]]+zero)
        mat[r+1][c]=mat[r][c+1]=mat[r][c]=mat[r+1][c+1]=0
    for r in range(0,n-1,2):
        for c in range(0,m-1,2):
            cal(r,c)
    if n%2:
        for c in range(0,m-1,2):
            cal(n-2,c)
    if m%2:
        for r in range(0,n-1,2):
            cal(r,m-2)
    if n%2 and m%2:
        cal(n-2,m-2)
    print(len(ans))
    for i in ans:
        print(*i)