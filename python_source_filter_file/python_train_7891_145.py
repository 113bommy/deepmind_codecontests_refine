s=input()
ans=1000
for i in range(len(s)-3):
  ans=min(ans,abs(753-int(s[i:i+3])))
print(ans)