a,b,c=map(int,input().split())
for i in range(100):
  if int(i*1.08)==a and int(i*1.1)==b:
    print(i)
    exit(0)
print(-1)