k,s=map(int,input().split())
count=0
for x in range(k+1):
  for y in range(k+1):
      if k>=s-x-y>=0:
        count+=1
print(count)