h,n=map(int,input().split())
AB=[list(map(int,input().split())) for _ in range(n)]

length=h+max(AB)[0]
DP=[float("inf")]*length
DP[0]=0

for i in range(h):
    for a,b in AB:
        DP[i+a]=min(DP[i+a],DP[i]+b)

print(min(DP[h:]))