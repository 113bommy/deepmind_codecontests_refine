S=list(input())
T=list(input())
len0=len(S)
S=S*(len(T)//len0+1)

S=S+S

p=26
mod=(1<<31)+7# 互いに素なものを指定

TABLE=[0]# Rolling Hashのテーブル. 最初は0
LEN=len(S)

for i in range(LEN):
    TABLE.append((p*TABLE[-1]%mod+ord(S[i])-97)%mod)# テーブルを埋める

NOW=0
LEN2=len(T)

for i in range(LEN2):
    NOW=(p*NOW%mod+ord(T[i])-97)%mod

TH=NOW

def hash_ij(i,j): # [i,j)のハッシュ値を求める
    return (TABLE[j]-TABLE[i]*pow(p,j-i,mod))%mod

OK=[0]*LEN

for i in range(LEN2,LEN):
    if hash_ij(i-LEN2,i)==TH:
        OK[i-LEN2]=1

OK=OK[:len0]

ANS=0

ST=[-1]*len0

for i in range(len0):
    if OK[i]==1 and ST[i]==-1:

        j=i
        count=0

        while OK[j]==1:
            
            if ST[j]!=-1:
                count+=ST[j]
                break
            
            count+=1
            ST[j]=1
            j=(j+LEN2)%len0
            if j==i:
                print(-1)
                import sys
                sys.exit()

        ST[i]=count
        ANS=max(ANS,count)

print(ANS)
