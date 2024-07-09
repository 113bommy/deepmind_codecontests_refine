n=int(input())
S=input()

ans=0
import itertools
itr=itertools.product(list("1234567890"),repeat=3)

for it in itr:
    cnt=0
    for i in range(n):
        if S[i]==it[cnt]:
            cnt+=1
        if cnt==3:
            ans+=1
            break

print(ans)