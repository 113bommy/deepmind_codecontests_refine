n = int(input())
S = [int(s) for s in input().split()]

q = int(input())
T = [int(t) for t in input().split()]
 
cnt = sum(t in S for t in T)
 
print(cnt)