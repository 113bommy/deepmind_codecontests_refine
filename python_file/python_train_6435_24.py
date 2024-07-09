K=input()
D=int(input())
#余り0,余り1,余り2,…,余り(D-1)
dp=[0]*D
mod=10**9+7
s=0
for i in range(len(K)):
  ndp=[0]*D
  #余りがjだったものは(j+d)%Dの余りに変わるので
  for j in range(D):
    for d in range(10):
      ndp[(j+d)%D]=(ndp[(j+d)%D]+dp[j])%mod
  #直前までKと数字が同じだったものをカウント
  for d in range(int(K[i])):
    ndp[(s+d)%D]+=1 
  dp=ndp
  s=(s+int(K[i]))%D
#0000…の場合を引き、もしもKが該当するなら1を加える
ans=dp[0]-1
if s%D==0:
  ans+=1
print(ans%mod)