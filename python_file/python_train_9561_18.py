N,K=map(int,input().split())
A=[list(map(int, input().split())) for i in range(N)]
B,C=zip(*A)
S=10**36
for left in B:
  for right in B:
    for up in C:
      for down in C:
        if left<right and down<up:
          cnt=0
          for x,y in A:
            if left<=x<=right and down<=y<=up:
              cnt+=1
          if cnt>=K:
            S=min(S,(right-left)*(up-down))
print(S)            