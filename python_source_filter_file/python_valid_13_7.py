'''Author- Akshit Monga'''
from sys import stdin, stdout
input = stdin.readline
import random
t = int(input())
for _ in range(t):
    n,m,k=map(int,input().split())
    change=0
    if m%2:
        change=1
        n,m=m,n
        k=(n*m)//2-k
    vv=m*(n//2)
    hh=0
    if n%2:
        hh=m//2
    ans="no"
    assert vv%2==0
    mat=[['?' for i in range(m)] for j in range(n)]
    val=97
    for i in range(0,n,2):
        val=-1
        if i==n-1:
            last=-1
            for j in range(0,m,2):
                block=[last]
                if i-1>=0:
                    block.append(ord(mat[i-1][j]))
                    block.append(ord(mat[i-1][j+1]))
                while 1:
                    ran=random.randint(97,97+25)
                    if ran not in block:
                        break
                mat[i][j]=chr(ran)
                mat[i][j+1]=chr(ran)
                last=ran
            continue
        for j in range(m):
            block=set()
            if i-1>=0:
                block.add(ord(mat[i-1][j]))
            if j-1>=0:
                block.add(ord(mat[i][j-1]))
            while 1:
                ran = random.randint(97, 97 + 25)
                if ran not in block:
                    mat[i][j] = chr(ran)
                    mat[i + 1][j] = chr(ran)
                    break
    # for i in mat:
    #     print(*i)
    r=0
    c=0
    while 1:
        if hh==k:
            ans="yes"
            break
        if vv==0:
            break
        hh+=2
        vv-=2
        # print(r,c)
        block=set()
        if r-1>=0:
            block.add(ord(mat[r-1][c]))
            block.add(ord(mat[r-1][c+1]))
        if r+1<n:
            block.add(ord(mat[r+1][c]))
            block.add(ord(mat[r+1][c+1]))
        if c-1>=0:
            block.add(ord(mat[r][c-1]))
            block.add(ord(mat[r+1][c-1]))
        if c+1<m:
            block.add(ord(mat[r][c+1]))
            block.add(ord(mat[r+1][c+1]))
        while 1:
            ran = random.randint(97, 97 + 25)
            if ran not in block:
                block.add(ran)
                mat[r][c]=chr(ran)
                mat[r][c+1]=chr(ran)
                break
        while 1:
            ran = random.randint(97, 97 + 25)
            if ran not in block:
                block.add(ran)
                mat[r+1][c]=chr(ran)
                mat[r+1][c+1]=chr(ran)
                break
        if hh==k:
            ans="yes"
            break
        c+=2
        if c>=m:
            c=0
            r+=2
    print(ans.upper())
    if ans == "no":
        continue
    if change:
        mat2 = [['' for i in range(n)] for j in range(m)]
        for i in range(n):
            for j in range(m):
                mat2[j][i] = mat[i][j]
        mat=mat2
    for i in mat:
        print(''.join(i))