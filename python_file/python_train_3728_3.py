# coding: utf-8
# Your code here!

x,y,z,k = map(int,input().split())

A = sorted(map(int,input().split()),reverse=True)
B = sorted(map(int,input().split()),reverse=True)
C = sorted(map(int,input().split()),reverse=True)



AB = sorted([a+b for a in A for b in B],reverse=True)

ans = sorted([ab + c for ab in AB[:k] for c in C],reverse=True)

for i in ans[:k]:
    print(i)
