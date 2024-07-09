import sys
stdin = sys.stdin
 
sys.setrecursionlimit(10**8) 
 
def li(): return map(int, stdin.readline().split())
def li_(): return map(lambda x: int(x)-1, stdin.readline().split())
def lf(): return map(float, stdin.readline().split())
def ls(): return stdin.readline().split()
def ns(): return stdin.readline().rstrip()
def lc(): return list(ns())
def ni(): return int(stdin.readline())
def nf(): return float(stdin.readline())

# D以下orUより大きい場所への遷移
def to0or4(base: int, nex: int):
    return base + nex

# Dより大きくS以下 or Gより大きくU以下の場所への遷移
def to1or3(base: int, nex: int):
    if nex == 0:
        return base + 2
    
    elif nex % 2:
        return base + 1
    
    else:
        return base


# Sより大きくG以下の場所への遷移
def to2(base: int, nex: int):
    if nex % 2:
        return base
    
    else:
        return base + 1
    
n = ni()
a = [ni() for _ in range(n)]
suma = sum(a)  

# 配るDP
dp = [[suma]*5 for _ in range(n+1)]
dp[0] = [0]*5

for i in range(n):
    for idx in range(5):
        for jdx in range(idx,5):
            
            if jdx == 0 or jdx == 4:
                dp[i+1][jdx] = min(dp[i+1][jdx],
                                   to0or4(dp[i][idx], a[i]))
            
            elif jdx == 1 or jdx == 3:
                dp[i+1][jdx] = min(dp[i+1][jdx],
                                   to1or3(dp[i][idx], a[i]))
                
            elif jdx == 2:
                dp[i+1][jdx] = min(dp[i+1][jdx],
                                   to2(dp[i][idx], a[i]))
   
print(min(dp[n]))