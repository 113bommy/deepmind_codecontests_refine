n,m=[int(x) for x in input().split()]
l=[[] for i in range(n)]
for i in range(m):
  a,b=map(int,input().split())
  l[a-1].append(b-1)
  l[b-1].append(a-1)
# print(l)

done=[0]*n


def dfs(j):
  que=[j]
  cnt=1
  done[j]=1
  while(que):
    now=que.pop(0)

    for i in l[now]:
      if done[i]!=1:
        que.append(i)
        done[i]=1
        cnt+=1

  return cnt

ma=0
for j in range(n):
  if done[j]!=1:
    now=dfs(j)
  else:
    now=0
  ma=max(now,ma)
  
print(ma)
