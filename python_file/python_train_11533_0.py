# -*- coding: utf-8 -*-

H,W = map(int, input().split())
Ch,Cw = map(int, input().split())
Dh,Dw = map(int, input().split())
S = [input() for _ in range(H)]

A = [[-1 for _ in range(W)] for _ in range(H)]
A[Ch-1][Cw-1] = 0

def isValid(h,w):
  if h>=0 and h<H and w>=0 and w<W and S[h][w]=='.' and A[h][w]==-1:
    return True
  else:
    return False

warp = 0
BFS_now = [(Ch-1, Cw-1)]
BFS_search = [(Ch-1, Cw-1)]
ij = [(-1,0),(0,-1),(0,1),(1,0)]
while len(BFS_now)>0:
  while len(BFS_search)>0:
    BFS_search_tmp = []
    for h,w in BFS_search:
      for i,j in ij:
        if isValid(h+i,w+j):
          BFS_search_tmp.append((h+i,w+j))
          A[h+i][w+j] = warp
    BFS_now += BFS_search_tmp
    BFS_search = BFS_search_tmp
  BFS_now_tmp = []
  for h,w in BFS_now:
    for i in range(-2,3):
      for j in range(-2,3):
        if isValid(h+i,w+j):
          BFS_now_tmp.append((h+i,w+j))
          A[h+i][w+j] = warp + 1
  BFS_now = BFS_now_tmp
  BFS_search = BFS_now_tmp
  warp += 1

print(A[Dh-1][Dw-1])