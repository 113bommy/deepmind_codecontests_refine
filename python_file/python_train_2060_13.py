N="0"+input()
N=N[::-1]
DP=[[0,0]for i in range(len(N))]

DP[0][0]=int(N[0])
DP[0][1]=10-int(N[0])

#print(DP)
#print(N)
for i in range(1,len(N)):
    DP[i][0]=min(DP[i-1][0]+int(N[i]),DP[i-1][1]+int(N[i])+1)
    DP[i][1]=min(DP[i-1][0]+10-int(N[i]),DP[i-1][1]+10-(int(N[i])+1))
#print(DP)
print(min(DP[-1]))