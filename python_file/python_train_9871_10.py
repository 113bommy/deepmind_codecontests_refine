import sys
input = sys.stdin.readline
n = int(input())
h = tuple(map(lambda x:int(x)-1,input().split()))
a = tuple(map(int,input().split()))

#update(i,x):Aiをxに更新する
def update(i,x):
    k = i + num - 1
    while k >= 0:
        seg[k] = max(x,seg[k])
        k = (k-1)//2

#query(a,b,0,0,num):[a,b)の最大値
def query(a,b,k,l,r):
    if r <= a or b <= l:
        return -float("inf")
    elif a <= l and r <= b:
        return seg[k]
    else:
        return max(query(a,b,2*k+1,l,(l+r)//2),query(a,b,2*k+2,(l+r)//2,r))

#初期化
#num : nより大きい最小の2のべき乗
num = 1
while num <= n:
    num *= 2
seg = [0]*(2*num-1)

#dp[i]:i番目が最後となる時の美しさの最大値
dp = [a[0]] + [0]*(n-1)
update(h[0],a[0])
for i in range(1,n):
    dp[i] = max(0,query(0,h[i],0,0,num))+a[i]
    update(h[i],dp[i])

print(max(dp))
