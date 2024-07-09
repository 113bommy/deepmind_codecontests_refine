n=int(input())
ass=0
for j in range(1,n+1):
  ass+=int(n/j)*(int(n/j)+1)*j//2
  
print(ass)