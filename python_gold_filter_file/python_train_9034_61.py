s=input()
t=input()
ans=0
for i in range(3):
	if s[i] is t[i]:
		ans+=1
print(ans)