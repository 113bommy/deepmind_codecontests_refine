import sys
sys.setrecursionlimit(10**7)

h,w=map(int,input().split())
s=[input() for _ in range(h)]
flag = [[0]*w for _ in range(h)]

def dfs(th,tw):
    global flag,h,w,s
    flag[th][tw] = True
    tblack = 0
    twhite = 0
    if s[th][tw] == "#":
        tblack += 1
    else:
        twhite += 1 
    for x,y in ([0,1],[0,-1],[1,0],[-1,0]):
        nth = th + x
        ntw = tw + y
        if nth >= 0 and nth < h and ntw >= 0 and ntw < w:
            if not flag[nth][ntw] and s[th][tw] != s[nth][ntw]:
                ttb,ttw = dfs(nth,ntw)
                tblack += ttb
                twhite += ttw
    return [tblack,twhite]
                
def main():
    global flag,h,w,s
    res = 0
    for i in range(h):
        for j in range(w):
            if not flag[i][j]:
                black,white = dfs(i,j)
                res += black * white 

    return res
print(main())