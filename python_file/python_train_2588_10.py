import sys
input = sys.stdin.readline
H,W,N = map(int,input().split())
count = []
L = 0
for i in range(N):
    a,b = map(int, input().split())
    a -= 1
    b -= 1
    for i in range(max(0,a-2),min(a+1,H-2)):
        for j in range(max(0,b-2),min(b+1,W-2)):
            count.append((i,j))
            L += 1
count.sort()
ans = [0]*10
tmp = 1
for i in range(L-1):
    if count[i] == count[i+1]:
        tmp += 1
    else:
        ans[tmp] += 1
        tmp = 1
if L>=1:
  ans[tmp] += 1
ans[0] = (H-2)*(W-2)-sum(ans)
for i in range(10):
    print(ans[i])