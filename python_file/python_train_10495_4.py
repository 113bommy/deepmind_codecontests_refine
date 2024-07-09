H, W = map(int, input().split())
S = [0]*(H+2)
S[0] = '*'*(W+2)
S[H+1] = '*'*(W+2)
for h in range(1,H+1):
  S[h] = '*' + input() + '*'

import sys
sys.setrecursionlimit(10**8)

bw = ['#','.']

visited = [[False]*(W+2) for h in range(H+2)]
ans = 0
dh = [0,1,0,-1]
dw = [1,0,-1,0]

def dfs(h,w,c):
  #print(h,w,c, bw_count)
  for i in range(4):
    h0 = h+dh[i]
    w0 = w+dw[i]
    if S[h0][w0]==bw[c^1] and visited[h0][w0]==False:
      visited[h0][w0]=True
      bw_count[c^1]+=1
      dfs(h0,w0,c^1)
  
for h in range(H+2):
  for w in range(W+2):
    if S[h][w]=='#' and visited[h][w]==False:
      bw_count = [1,0]
      visited[h][w]=True
      dfs(h,w,0)
      ans += bw_count[0]*bw_count[1]

print(ans)   

#print(*ans, sep='\n')
