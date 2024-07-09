#!/usr/bin/python3
# -*- coding:utf-8 -*-

def main():
  n = int(input())
  board = []
  for _ in range(n):
    board.append(list(input().strip()))
  
  def judge(ia):
    for i in range(n):
      for j in range(i+1, n):
        if board[(i+ia)%n][j] != board[(j+ia)%n][i]:
          return False
    return True
  
  cnt = 0 
  for ia in range(n):
    if judge(ia):
      cnt += 1
  print(n * cnt)
  
if __name__=='__main__':
  main()

